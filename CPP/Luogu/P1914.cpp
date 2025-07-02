#include <bits/stdc++.h>
using namespace std;

int main() {
    const int MAX_LENGTH = 200;
    char a[MAX_LENGTH];
    int n, la;
    int b[MAX_LENGTH];

    cin >> n >> a;
    la = strlen(a);

    for (int i = 0; i < la; i++) {
        b[i] = a[i];
        b[i] += n;
        
        if (b[i] > 122) {
            b[i] = (b[i] % 122) + 96;
        }
    }

    for (int i = 0; i < la; i++) {
        a[i] = b[i];
        cout << a[i];
    }

    return 0;
}