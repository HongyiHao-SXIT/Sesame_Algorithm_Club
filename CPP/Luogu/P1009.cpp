#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> multiply(const vector<int>& a, int b) {
    vector<int> result;
    int carry = 0;
    
    for (size_t i = 0; i < a.size() || carry; ++i) {
        if (i < a.size()) {
            carry += a[i] * b;
        }
        result.push_back(carry % 10);
        carry /= 10;
    }

    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }
    
    return result;
}

vector<int> add(const vector<int>& a, const vector<int>& b) {
    vector<int> result;
    int carry = 0;
    
    for (size_t i = 0; i < a.size() || i < b.size() || carry; ++i) {
        if (i < a.size()) carry += a[i];
        if (i < b.size()) carry += b[i];
        result.push_back(carry % 10);
        carry /= 10;
    }
    
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<int> sum(1, 0);
    vector<int> factorial(1, 1);
    
    for (int i = 1; i <= n; ++i) {
        factorial = multiply(factorial, i);
        sum = add(sum, factorial);
    }
    
    for (auto it = sum.rbegin(); it != sum.rend(); ++it) {
        cout << *it;
    }
    cout << '\n';
    
    return 0;
}