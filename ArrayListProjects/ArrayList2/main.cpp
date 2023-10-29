#include <iostream>
#include "ArrayList.h"
#include <string>

using namespace std;

int main()
{

    ArrayList<int> numbers;
    numbers.append(0);
    numbers.append(1);
    numbers.append(2);
    numbers.append(3);
    numbers.append(4);
    // ArrayList<string> names;

    // names.append("Alice");
    // string me = names.get(0);
    // cout << me << endl;
    numbers.reverse();

    cout << numbers << endl;

    return 0;
}