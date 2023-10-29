#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

using namespace std;

template <typename T>
struct ArrayList
{
    int capacity;
    int count;
    T *data;

    ArrayList()
    {
        capacity = 1;
        count = 0;
        data = new T[capacity];
    }

    void inflate()
    {
        if (count == capacity)
        {
            int newCapacity = capacity * 2;
            T *temp = new T[newCapacity];
            for (int i = 0; i < count; i++)
            {
                temp[i] = data[i];
            }

            T *old = data;
            data = temp;
            capacity = newCapacity;

            delete[] old;
        }
    }

    T get(int index) const
    {
        return data[index];
    }

    void append(T x)
    {
        data[count] = x;
        count++;
        inflate();
    };

    void reverse()
    {
        int start = 0;
        int end = count - 1;

        while (start < end)
        {
            // Swap the elements at the start and end indices
            int temp = data[start];
            data[start] = data[end];
            data[end] = temp;

            // Move the start and end indices towards the center
            start++;
            end--;
        }
    }
};
template <class T>
std::ostream &operator<<(std::ostream &os, ArrayList<T> &list)
{
    for (int i = 0; i < list.count; i++)
    {
        os << list.data[i];
        if (i < list.count - 1)
        {
            os << ", ";
        }
    }

    return os;
}

#endif