#ifndef FUNKYSTACK_H
#define FUNKYSTACK_H

#include "Queue.h"
#include <iostream>
#include <ostream>
#include <stdexcept>

using namespace std;

template <typename T>
struct FunkyStack
{
    Queue<T> q;
    void push(T x)
    {
        q.enqueue(x);
        for (int i = 0; i < q.length() - 1; i++)
        {
            q.enqueue(q.dequeue());
        }
    }
    T pop()
    {
        return q.dequeue();
    }
};

#endif