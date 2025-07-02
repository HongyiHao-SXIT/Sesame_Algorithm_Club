#include <iostream>
using namespace std;

struct Distance {
    int feet;
    float inch;
};

int main() {
    Distance* ptr, d;
    ptr = &d;

    cout << "Enter feet: ";
    cin >> ptr->feet;
    cout << "Enter inches: ";
    cin >> ptr->inch;

    cout << "\nDisplaying Information" << endl;
    cout << "Distance = " << ptr->feet << " feet " << ptr->inch << " inches";

    return 0;
}