#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList<int> myList;
    myList.append(0);
    myList.append(1);

    LinkedList<int> myList2(myList);
    myList2.prepend(-1);

    LinkedList<int> myList3 = myList2;
    myList3.append(2);

    LinkedList<int> myList4;
    myList4 = myList3;

    myList4.prepend(-2);

    // myList.append(2);
    // myList.append(3);
    // myList.append(4);

    // myList.removeFirst();
    myList.removeLast();

    cout << "first element of the list is: " << myList.peek() << endl;

    // myList.prepend(0);

    // myList.insert(5, 5);

    // myList.deleteAt(1);

    // myList.reverse();

    cout << myList << endl;
    cout << myList2 << endl;
    cout << myList3 << endl;
    cout << myList4 << endl;
    return 0;
}