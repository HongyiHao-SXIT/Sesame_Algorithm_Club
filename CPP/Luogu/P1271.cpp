#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 2000000;
int a[MAX_SIZE];
int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }
    
    sort(a, a + m);
    
    for (int i = 0; i < m; ++i) {
        cout << a[i] << " \n"[i == m - 1];
    }
    
    return 0;
}