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
        if (this == &other)
        {
            return *this;
        }
        delete[] arr;

        count = other.count;
        capacity = other.capacity;
        arr = new T[capacity];
        for (int i = 0; i < count; i++)
        {
            arr[i] = other.arr[i];
        }

        return *this;
    }

    ~ArrayList()
    {
        delete[] arr;
    }

    void inflate()
    {
        if (count == capacity)
        {
            int newCapacity = capacity * 2;
            T *temp = new T[newCapacity];
            for (int i = 0; i < count; i++)
            {
                temp[i] = arr[i];
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
                temp[i] = arr[i];
            }
            T *old = arr;
            arr = temp;
            delete old;
            capacity = newCapacity;
        }
    }

    void append(T value)
    {
        arr[count] = value;
        count++;
        inflate();
    }

    void prepend(T value)
    {
        for (int i = count; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = value;
        count++;
        inflate();
    }

    void removeFirst()
    {

        for (int i = 1; i < count; i++)
        {
            arr[i - 1] = arr[i];
        }
        count--;
        deflate();
    }

    void removeLast()
    {
        count--;
        deflate();
    }

    void insert(T value, int index)
    {
        append(value);
        for (int i = count - 1; i > index; i--)
        {
            T temp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = temp;
        }
    }

    void reverse()
    {
        int front = 0;
        int back = count - 1;
        while (front < back)
        {
            T temp = arr[front];
            arr[front] = arr[back];
            arr[back] = temp;
            back--;
            front++;
        }
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