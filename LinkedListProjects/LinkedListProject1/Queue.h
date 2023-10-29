#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <ostream>
#include <stdexcept>
#include "LinkedList.h"
using namespace std;
template <class T>
class Queue
{
private:
public:
    LinkedList<T> elements;
    void enqueue(T value)
    {
        elements.append(value);
    }
    T dequeue()
    {
        return elements.removeFirst();
    }
    T peek() const
    {
        return elements.peek();
    }
    int length() const
    {
        return elements.size();
    }
    bool isEmpty() const
    {
        return elements.isEmpty();
    }

    template <class U>
    friend std::ostream &operator<<(std::ostream &os, const Queue<U> &queue);
};

template <class T>
std::ostream &operator<<(std::ostream &os, const Queue<T> &queue)
{
    os << queue.elements;
    return os;
}

#endif