#include <iostream>
#include "ArrayList.h"

using namespace std;

int main()
{

    ArrayList<int> numbers;

    numbers.append(5);
    numbers.append(7);
    numbers.append(9);

    numbers.prepend(3);

    numbers.insert(10, 4);

    // ArrayList<int> temp = numbers;

    // numbers.reverse();

    ArrayList<int> numbers2 = numbers;
    numbers2.prepend(0);

    ArrayList<int> numbers3;
    numbers3 = numbers;

    numbers3.append(11);
    numbers3.removeFirst();

    cout << numbers << endl;
    cout << numbers2 << endl;
    cout << numbers3 << endl;
    // cout << temp << endl;

    // temp.removeFirst();
    // numbers.removeFirst();
    // numbers.removeLast();

    // cout << numbers << endl;
    // cout << temp << endl;

    // numbers = temp;

    return 0;
}