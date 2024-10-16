//Name: - Manas Gautam
//PRN: - 23070123081
//Batch: - E&Tc {B}

// Experimnet 10 A: -

#include <iostream>
using namespace std;

void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "Inside function: a = " << a << ", b = " << b << endl;  // swapped values inside the function
}

int main() {
    int x = 10, y = 20;
    cout << "Before function call: x = " << x << ", y = " << y << endl;

    swapByValue(x, y);  // call by value: the changes won't reflect in x and y

    cout << "After function call: x = " << x << ", y = " << y << endl;  // original values remain unchanged
    return 0;
}

// Experiment 10 B: - 

#include <iostream>
using namespace std;

void swapByReference(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10, y = 20;
    cout << "Before swapping: x = " << x << ", y = " << y << endl;

    swapByReference(x, y);  // call by reference: x and y will be swapped

    cout << "After swapping: x = " << x << ", y = " << y << endl;
    return 0;
}
