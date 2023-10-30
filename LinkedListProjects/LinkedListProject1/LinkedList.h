#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <ostream>
#include <stdexcept>

using namespace std;

template <class T>
struct Link
{
    T data;
    Link *prev;
    Link *next;

    Link()
    {
        data = 0;
        prev = nullptr;
        next = nullptr;
    }
    Link(T value)
    {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

template <class T>
class LinkedList
{
private:
public:
    int arrSize;
    Link<T> *front;
    Link<T> *back;

    LinkedList()
    {
        arrSize = 0;
        front = nullptr;
        back = nullptr;
    }

    void append(T value)
    {
        if (front == nullptr)
        {
            front = new Link<T>(value);
            back = front;
            arrSize++;
        }
        else
        {
            Link<T> *temp = new Link<T>(value);
            temp->prev = back;
            back->next = temp;
            back = temp;
            arrSize++;
        }
    }

    LinkedList(const LinkedList &other)
    {
        Link<T> *curr = other.front;
        while (curr != nullptr)
        {
            this->append(curr->data);
            curr = curr->next;
        }
    }

    LinkedList &operator=(const LinkedList &other)
    {
        if (this == &other)
        {
            return *this; // Avoid self-assignment
        }

        // Clear the current list
        while (front != nullptr)
        {
            Link<T> *temp = front;
            front = front->next;
            delete temp;
        }
        front = back = nullptr;

        Link<T> *curr = other.front;
        this->arrSize = 0;
        while (curr != nullptr)
        {
            this->append(curr->data);
            curr = curr->next;
        }

        return *this;
    }

    void prepend(T value)
    {
        if (front == nullptr)
        {
            front = new Link<T>(value);
            back = front;
            arrSize++;
        }
        else
        {
            Link<T> *temp = new Link<T>(value);
            temp->next = front;
            front->prev = temp;
            front = temp;
            arrSize++;
        }
    }

    T removeFirst()
    {
        if (front == nullptr)
        {
            throw logic_error("there is nothing to remove");
        }
        else if (front == back)
        {
            T value = front->data;
            delete front;
            back = front = nullptr;
            arrSize--;
            return value;
        }
        else
        {
            T value = front->data;
            Link<T> *old = front;
            front = front->next;
            delete old;
            arrSize--;
            return value;
        }
    }
    void removeLast()
    {
        if (front == nullptr)
        {
            throw logic_error("there is nothing to remvoe");
        }
        else if (front == back)
        {
            delete front;
            front = back = nullptr;
            arrSize--;
        }
        else
        {
            Link<T> *old = back;
            back = back->prev;
            back->next = nullptr;
            delete old;
            arrSize--;
        }
    }

    void insert(T value, int index)
    {
        if (index < 0 || index > arrSize)
        {
            // Handle invalid index, throw an exception, or do nothing.
            throw logic_error("insertion out of bound");
        }

        Link<T> *temp = new Link<T>(value);

        if (arrSize == 0)
        {
            front = back = temp;
        }
        else
        {
            if (index == 0)
            {
                // Insert at the beginning
                temp->next = front;
                front->prev = temp;
                front = temp;
                if (arrSize == 0)
                {
                    // If the list was empty, update 'back' as well
                    back = temp;
                }
            }
            else
            {
                Link<T> *curr = front;
                for (int i = 0; i < index - 1; i++)
                {
                    curr = curr->next;
                }
                temp->next = curr->next;
                temp->prev = curr;
                curr->next = temp;

                if (curr == back)
                {
                    // If inserting at the end, update 'back'
                    back = temp;
                }
            }
        }

        arrSize++;
    }

    void addSorted(T value)
    {
        Link<T> *curr = front;
        int index = 0;
        while (curr != nullptr && curr->data < value)
        {
            curr = curr->next;
            index++;
        }
        insert(value, index);
    }

    void reverse()
    {
        Link<T> *curr = front;
        Link<T> *temp = nullptr;
        while (curr != nullptr)
        {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }

        Link<T> *temp_front = front;
        front = back;
        back = temp_front;
    }

    int size() const
    {
        return arrSize;
    }

    bool isEmpty() const
    {
        return arrSize == 0;
    }

    template <class U>
    friend std::ostream &operator<<(std::ostream &os, const LinkedList<U> &list);
};

template <class T>
std::ostream &operator<<(std::ostream &os, const LinkedList<T> &list)
{
    Link<T> *curr = list.front;
    // cout << "front = " << list.front->data << endl;
    // cout << "back = " << list.back->data << endl;
    // cout << "curr->data = " << curr->data << endl;
    // cout << "curr->next->data = " << (curr->next->data) ? curr->next->data : "undefined" << endl;
    // curr->next ? cout << "curr->next->data = " << curr->next->data << endl : cout << "curr->next->data = undefined " << endl;

    while (curr != nullptr)
    {
        os << curr->data;
        if (curr != list.back)
        {
            os << ", ";
        }
        curr = curr->next;
    }
    return os;
    // Link<T> *curr = list.back;
    // while (curr != nullptr)
    // {
    //     os << curr->data;
    //     if (curr != list.front)
    //     {
    //         os << ", ";
    //     }
    //     curr = curr->prev;
    // }
    // return os;
}

#endif