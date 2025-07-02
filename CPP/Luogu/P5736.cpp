#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

bool isprime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int n, a;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> a;
        if (isprime(a)) {
            cout << a << " ";
        }
    }
    
    return 0;
}