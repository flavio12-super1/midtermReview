#include <iostream>
#include "LinkedList.h"
// #include "Stack.h"
// #include "Queue.h"
#include "FunkyStack.h"

using namespace std;

int main()
{
    LinkedList<int> myList;
    myList.append(1);
    myList.removeFirst();
    myList.removeFirst();
    cout << myList << endl;
    // myList.append(3);
    // myList.append(7);
    // myList.append(9);

    // myList.removeFirst();
    // myList.removeLast();

    // myList.reverse();
    // myList.insert(8, 3);
    // myList.insert(2, 0);
    // myList.insert(3, 0);

    // myList.insert(0, 0);
    // myList.insert(10, myList.size());
    // LinkedList<int> myList2;
    // myList2.append(10);
    // myList2 = myList;
    // myList2.append(11);
    // myList2.insert(12, myList2.size());

    // myList2.insert(12, myList2.size());

    // LinkedList<int> myList3 = myList2;
    // myList3.append(15);

    // myList.addSorted(20);

    // cout << "arr size: " << myList.size() << endl;
    // cout << myList << endl;
    // cout << "arr size 2: " << myList2.size() << endl;
    // cout << myList2 << endl;
    // cout << "arr size 3: " << myList3.size() << endl;
    // cout << myList3 << endl;

    // cout << "--------------------" << endl;
    // {
    //     Queue<int> myQueue;
    //     int x;
    //     for (int i = 0; i < 5; i++)
    //     {
    //         cin >> x;
    //         myQueue.enqueue(x);
    //     }
    //     cout << myQueue << endl;
    // }
    // cout << "--------------------" << endl;
    // {
    //     Stack<int> myStack;
    //     int x;
    //     for (int i = 0; i < 5; i++)
    //     {
    //         cin >> x;
    //         myStack.push(x);
    //     }
    //     cout << myStack << endl;
    // }
    // cout << "--------------------" << endl;

    // {
    //     FunkyStack<int> myFunkyStack;
    //     int x;
    //     for (int i = 0; i < 5; i++)
    //     {
    //         cin >> x;
    //         myFunkyStack.push(x);
    //     }
    //     // Output the elements from the FunkyStack
    //     while (!myFunkyStack.q.isEmpty())
    //     {
    //         cout << myFunkyStack.pop() << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}