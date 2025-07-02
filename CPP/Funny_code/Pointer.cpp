#include <iostream>
using namespace std;

int main() {
    int *pc, c;
    
    c = 5;
    cout << "Address of c (&c): " << &c << endl;
    cout << "Value of c (c): " << c << endl << endl;

    pc = &c;
    cout << "Pointer pc holds address (pc): " << pc << endl;
    cout << "Value at address held by pc (*pc): " << *pc << endl << endl;
    
    c = 11; 
    cout << "Pointer pc holds address (pc): " << pc << endl;
    cout << "Value at address held by pc (*pc): " << *pc << endl << endl;

    *pc = 2; 
    cout << "Address of c (&c): " << &c << endl;
    cout << "Value of c (c): " << c << endl;

    return 0;
}