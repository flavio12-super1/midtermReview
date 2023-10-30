#ifndef ARRAY_LIST
#define ARRAY_LIST

#include <iostream>
#include <ostream>
#include <stdexcept>

using namespace std;

template <class T>
class ArrayList
{
private:
public:
    int count;
    int capacity;
    T *arr;

    ArrayList()
    {
        count = 0;
        capacity = 1;
        arr = new T[capacity];
    }

    ArrayList(const ArrayList &other)
    {
        count = other.count;
        capacity = other.capacity;
        arr = new T[capacity];
        for (int i = 0; i < count; i++)
        {
            arr[i] = other.arr[i];
        }
    }

    ArrayList &operator=(const ArrayList &other)
    {
        if (this == other)
        {
            return *this;
        }

        delete[] arr;

        count = other.count;
        capacity = other.capacity;
        T *arr = new T[capacity];
        for (int i = 0; i < count; i++)
        {
            arr[i] = other.arr[i];
        }
        return *this;
    }

    void inflate()
    {
        if (count == capacity)
        {
            int newCapacity = capacity * 2;
            T *temp = new T[newCapacity];
            for (int i = 0; i < count; i++)
            {
                temp[i] = this->arr[i];
            }
            T *old = arr;
            arr = temp;
            delete old;
            capacity = newCapacity;
        }
    }

    void deflate()
    {
        if (count < capacity / 2)
        {
            int newCapacity = capacity / 2;
            T *temp = new T[newCapacity];
            for (int i = 0; i < count; i++)
            {
                temp[i] = this->arr[i];
            }
            T *old = arr;
            arr = temp;
            delete old;
            capacity = newCapacity;
        }
    }

    T &operator[](int index)
    {
        cout << "pain: " << count << endl;
        if (index < 0 || index >= count)
        {
            throw logic_error("index out of bound you idiot");
        }

        return arr[index];
    }

    void append(T value)
    {
        inflate();
        arr[count] = value;
        count++;
    }

    void prepend(T value)
    {
        inflate();
        for (int i = count; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = value;
        count++;
    }

    void removeFirst()
    {
        if (count == 0)
        {
            throw logic_error("nothing to remove");
        }
        count--;
        for (int i = 0; i < count; i++)
        {
            arr[i] = arr[i + 1];
        }

        deflate();
    }

    void removeLast()
    {
        if (count == 0)
        {
            throw logic_error("nothing to remove");
        }
        count--;
        deflate();
    }

    void reverse()
    {
        int start = 0;
        int end = count - 1;

        while (start < end)
        {
            T temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;

            start++;
            end--;
        }
    }

    // void insert(T value, int index)
    // {
    //     append(value);
    //     for (int i = count - 1; i > index; i--)
    //     {
    //         arr[i] = arr[i - 1];
    //     }
    //     arr[index] = value;
    // }
    void insert(T value, int index)
    {
        append(value);
        for (int i = count - 1; i > index; i--)
        {
            T temp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = temp;
        }
        // arr[index] = value;
    }

    T peek()
    {
        if (count == 0)
        {
            throw logic_error("nothing to peek at");
        }
        cout << arr[1];
        return arr[0];
    }

    int size() const
    {
        return this->count;
    }

    int getCapacity() const
    {
        return this->capacity;
    }

    bool isEmpty()
    {
        return count == 0;
    }

    ~ArrayList()
    {
        delete[] arr;
    }

    template <class U>
    friend std::ostream &operator<<(std::ostream &os, const ArrayList<U> &list);
};

template <class T>
std::ostream &operator<<(std::ostream &os, const ArrayList<T> &list)
{
    for (int i = 0; i < list.count; i++)
    {
        os << list.arr[i];
        if (i < list.count - 1)
        {
            os << ", ";
        }
    }
    return os;
}

#endif