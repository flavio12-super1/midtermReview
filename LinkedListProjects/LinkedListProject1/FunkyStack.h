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

                // Queue<T> temp;
        // temp.enqueue(x);

        // while (!q.isEmpty())
        // {
        //     temp.enqueue(q.dequeue());
        // }

        // while (!temp.isEmpty())
        // {
        //     q.enqueue(temp.dequeue());
        // }
    }
    T pop()
    {
        return q.dequeue();
    }
};

#endif