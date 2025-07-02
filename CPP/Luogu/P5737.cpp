#include <iostream>
#include <vector>

using namespace std;

bool is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int begin, end;
    cin >> begin >> end;

    vector<int> leap_years;
    leap_years.reserve((end - begin) / 4 + 1);

    for (int year = begin; year <= end; ++year) {
        if (is_leap_year(year)) {
            leap_years.push_back(year);
        }
    }

    cout << leap_years.size() << '\n';
    for (size_t i = 0; i < leap_years.size(); ++i) {
        cout << leap_years[i] << " \n"[i == leap_years.size() - 1];
    }

    return 0;
}