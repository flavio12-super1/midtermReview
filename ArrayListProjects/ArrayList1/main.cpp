#include <iostream>
#include "ArrayList.h"
using namespace std;

int main()
{

    ArrayList<int> myArray;
    myArray.append(1);
    {
        int value = myArray.peek();
        cout << "the first value in the array list is: " << value << endl;
    }
    myArray.removeLast();
    myArray.append(2);
    myArray.append(3);
    myArray.removeFirst();
    myArray.prepend(0);
    myArray.removeLast();

    {
        int value = myArray.size();
        cout << "arr size is: " << value << endl;
    }

    {
        int value = myArray.getCapacity();
        cout << "arr capacity is: " << value << endl;
    }
    {
        int value = myArray.peek();
        cout << "the first value in the array list is: " << value << endl;
    }
    if (myArray.isEmpty())
    {
        cout << "array is empty" << endl;
    }
    else
    {
        cout << "array is not empty" << endl;
    }
    // cout << myArray[1] << endl;
    // int value = myArray[1];
    cout << myArray << endl;

    return 0;
}