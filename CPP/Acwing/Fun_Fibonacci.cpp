#include <iostream>

using namespace std;

int Fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main() {
    int num;
    cout << "Please enter the number you want to know: " << endl;
    cin >> num;
    
    cout << "The number is " << Fibonacci(num) << endl;
    return 0;
}