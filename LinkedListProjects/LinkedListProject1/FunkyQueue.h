#ifndef FUNKYQUEUE_H
#define FUNKYQUEUE_H

#include "Stack.h"
#include <iostream>
#include <ostream>
#include <stdexcept>

using namespace std;

template <typename T>
struct FunkyQueue
{
    Stack<T> s;
    void push(T x)
    {
        Stack<T> temp;
        s.push(x);
        while (!s.isEmpty())
        {
            temp.push(s.pop());
        }

        while (!temp.isEmpty())
        {
            s.push(temp.pop());
        }
    }
    T pop()
    {
        return s.pop();
    }
};

#endif