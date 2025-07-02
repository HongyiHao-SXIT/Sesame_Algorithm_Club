#include <iostream>
#include <algorithm>

using namespace std;

void printPattern(int N) {
    if (N == 0) return;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int value = min(min(i, N - i + 1), min(j, N - j + 1));
            cout << value;
            if (j < N) cout << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int N;
    while (cin >> N && N != 0) {
        printPattern(N);
    }
    return 0;
}