#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int l, m;
    cin >> l >> m;

    vector<pair<int, int>> intervals(m);
    for (auto& interval : intervals) {
        cin >> interval.first >> interval.second;
    }

    sort(intervals.begin(), intervals.end());

    int remaining = l + 1;
    int last = -1;

    for (const auto& [u, v] : intervals) {
        if (u > last) {
            remaining -= (v - u + 1);
            last = v;
        } else if (v > last) {
            remaining -= (v - last);
            last = v;
        }
    }

    cout << remaining << endl;

    return 0;
}