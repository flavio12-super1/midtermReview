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
    Link *next;
    Link *prev;

    Link()
    {
        data = 0;
        next = nullptr;
        prev = nullptr;
    }

    Link(T value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
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

    ~LinkedList()
    {
        while (front != nullptr)
        {
            Link<T> *temp = front;
            front = front->next;
            delete temp;
        }
        front = back = nullptr;
    }

    LinkedList(const LinkedList &other)
    {
        Link<T> *curr = other.front;
        while (curr != nullptr)
        {
            append(curr->data);
            curr = curr->next;
        }
    }

    LinkedList &operator=(const LinkedList &other)
    {
        if (this == &other)
        {
            return *this;
        }

        while (front != nullptr)
        {
            Link<T> *temp = front;
            front = front->next;
            delete temp;
        }
        Link<T> *curr = other.front;

        while (curr != nullptr)
        {
            append(curr->data);
            curr = curr->next;
        }

        return *this;
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
            front->prev = temp;
            temp->next = front;
            front = temp;
            arrSize++;
        }
    }

    void removeFirst()
    {
        if (front == nullptr)
        {
            throw std::logic_error("nothing to remove");
        }
        else
        {
            if (front == back)
            {
                delete front;
                front = back = nullptr;
                arrSize--;
            }
            else
            {
                Link<T> *temp = front;
                front = front->next;
                front->prev = nullptr;
                delete temp;
                arrSize--;
            }
        }
    }
    void removeLast()
    {
        if (front == nullptr)
        {
            throw std::logic_error("nothing to remove");
        }
        else if (front == back)
        {
            delete back;
            back = front = nullptr;
            arrSize--;
        }
        else
        {
            Link<T> *temp = back;

            back = back->prev;
            back->next = nullptr;
            delete temp;
            arrSize--;
        }
    }

    T peek()
    {
        if (front == nullptr)
        {
            throw std::logic_error("nothing to peek at");
        }
        return front->data;
        // return (front) ? front->data : throw std::logic_error("nothing to peek at");
    }

    void reverse()
    {
        Link<T> *curr = back;
        Link<T> *temp = nullptr;
        while (curr != nullptr)
        {

            temp = curr->next;
            curr->next = curr->prev;
            curr->prev = temp;

            curr = curr->next;
        }

        Link<T> *oldFront = front;
        front = back;
        back = oldFront;
    }

    void insert(T value, int index)
    {
        if (index < 0 || index > arrSize)
        {
            throw std::logic_error("out of bound");
        }
        Link<T> *curr = front;
        if (front == nullptr)
        {
            front = new Link<T>(value);
            back = front;
            arrSize++;
        }
        else
        {

            for (int i = 0; i < index - 1; i++)
            {

                curr = curr->next;
                cout << curr->data << endl;
            }
            Link<T> *temp = new Link<T>(value);
            temp->next = curr->next;
            temp->prev = curr;
            curr->next = temp;
            if (index == arrSize)
            {
                back = temp;
            }

            arrSize++;
        }
    }

    void deleteAt(int index)
    {
        if (index < 0 || index >= arrSize)
        {
            throw std::logic_error("out of bound");
        }
        Link<T> *curr = front;

        Link<T> *prev = nullptr;
        Link<T> *next = nullptr;
        if (index == 0)
        {
            Link<T> *temp = curr;
            front = front->next;
            delete temp;
        }
        else
        {

            for (int i = 0; i < index; i++)
            {

                curr = curr->next;
                prev = curr->prev;
                next = curr->next;
            }
            (prev != nullptr) ? cout << prev->data << endl : cout << "nullptr" << endl;
            cout << curr->data << endl;
            (next != nullptr) ? cout << next->data << endl : cout << "nullptr" << endl;

            Link<T> *temp = curr;
            if (next != nullptr)
            {
                prev->next = next;
                next->prev = prev;
            }
            else
            {
                prev->next = next;
                back = prev;
            }
            delete temp;
        }
        arrSize--;
    }

    template <class U>
    friend std::ostream &operator<<(std::ostream &os, const LinkedList<U> &list);
};

template <class T>
std::ostream &operator<<(std::ostream &os, const LinkedList<T> &list)
{
    Link<T> *curr = list.front;
    while (curr != nullptr)
    {
        os << curr->data;
        if (curr != list.back)
        {
            os << ", ";
        }
        curr = curr->next;
    }
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
    return os;
}

#endif