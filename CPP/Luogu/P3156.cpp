#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 2000001;
long long a[MAX_SIZE];

int main() {
    long long n, m, x;
    
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    for (int i = 1; i <= m; ++i) {
        cin >> x;
        cout << a[x] << endl;
    }
    
    return 0;
}