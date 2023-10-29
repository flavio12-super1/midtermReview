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
        Link<T> *temp = front;
        front = front->next;
        delete temp;
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
            back->next = temp;
            temp->prev = back;
            back = temp;
            arrSize++;
        }
    }

    // void reverse()
    // {
    //     Link<T> *oldFront = front;
    //     front = back;
    //     back = oldFront;

    //     Link<T> *curr = front;
    //     while (curr != nullptr)
    //     {
    //         Link<T> *prev = curr;
    //         curr->next = curr->prev;
    //         curr->prev = prev->next;

    //         curr = curr->next;
    //     }
    // }

    // void reverse()
    // {
    //     Link<T> *oldFront = front;
    //     front = back;
    //     back = oldFront;

    //     Link<T> *curr = front;
    //     while (curr != nullptr)
    //     {
    //         curr->next = curr->prev;
    //         curr->prev = curr->next;

    //         curr = curr->next;
    //     }
    // }

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

        // Link<T> *curr2 = back;
        // while (curr2 != nullptr)
        // {
        //     cout << curr2->data;
        //     if (curr2->prev != nullptr)
        //     {
        //         cout << ", ";
        //     }
        //     curr2 = curr2->prev;
        // }

        // Link<T> *curr2 = front;
        // while (curr2 != nullptr)
        // {
        //     cout << curr2->data;
        //     if (curr2->next != nullptr)
        //     {
        //         cout << ", ";
        //     }

        //     curr2 = curr2->next;
        // }
        // cout << endl;
       }

    // void reverse()
    // {
    //     Link<T> *curr = front;
    //     Link<T> *prev = nullptr;
    //     while (curr != nullptr)
    //     {
    //         // Link<T> *next = curr;
    //         // curr->next = ;
    //         // curr->prev = prev->next;
    //         Link<T> *next = curr;
    //         curr->next = curr->prev;
    //         curr->prev = next->next;

    //         curr = curr->next;
    //     }

    //     Link<T> *oldFront = front;
    //     front = back;
    //     back = oldFront;
    // }

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
    return os;
}

#endif