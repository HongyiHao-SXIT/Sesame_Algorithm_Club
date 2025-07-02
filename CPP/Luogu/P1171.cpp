#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;

int q[N];

void quick_sort(int q[], int l, int r) {
    if (l >= r) return;

    int i = l - 1, j = r + 1;
    int pivot = q[l + ((r - l) >> 1)];
    
    while (i < j) {
        do i++; while (q[i] < pivot);
        do j--; while (q[j] > pivot);
        if (i < j) swap(q[i], q[j]);
    }

    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> q[i];
    }

    quick_sort(q, 0, n - 1);

    for (int i = 0; i < n; ++i) {
        cout << q[i] << " \n"[i == n - 1];
    }

    return 0;
}