#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList<int> myList;
    myList.append(0);
    myList.append(1);
    myList.append(2);
    myList.append(3);
    myList.append(4);

    myList.reverse();

    cout << myList << endl;
    return 0;
}