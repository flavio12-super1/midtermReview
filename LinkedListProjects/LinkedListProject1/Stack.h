#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <ostream>
#include <stdexcept>

#include "LinkedList.h"
using namespace std;

template <class T>
class Stack
{
private:
public:
    LinkedList<T> elements;
    void push(T value)
    {
        elements.prepend(value);
    }
    T pop()
    {
        return elements.removeFirst();
    }
    T peek()
    {
        return elements.peek();
    }
    int length()
    {
        return elements.size();
    }

    template <class U>
    friend std::ostream &operator<<(std::ostream &os, const Stack<U> &stack);
};

template <class T>
std::ostream &operator<<(std::ostream &os, const Stack<T> &stack)
{
    os << stack.elements;
    return os;
}

#endif