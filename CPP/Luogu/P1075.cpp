#include <iostream>
#include <cmath>

using namespace std;

int find_smallest_factor(int n) {
    if (n % 2 == 0) return n / 2;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return n / i;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    
    cout << find_smallest_factor(n) << endl;
    return 0;
}