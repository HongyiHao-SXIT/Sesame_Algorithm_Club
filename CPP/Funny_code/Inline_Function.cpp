#include <iostream>

using namespace std;

const double PI = 3.14159265358979;

inline double calArea(double radius){
    return PI * radius *radius;
}

int main(){
    double r = 3;

    double area = calArea(r);
    return 0;
}