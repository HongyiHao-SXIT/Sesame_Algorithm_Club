#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> winning_numbers(7);
    for (int& num : winning_numbers) {
        cin >> num;
    }
    sort(winning_numbers.begin(), winning_numbers.end());

    vector<int> awards(7);

    while (n--) {
        vector<int> ticket(7);
        for (int& num : ticket) {
            cin >> num;
        }
        sort(ticket.begin(), ticket.end());

        vector<int> matches;
        set_intersection(winning_numbers.begin(), winning_numbers.end(),
                        ticket.begin(), ticket.end(),
                        back_inserter(matches));

        switch (matches.size()) {
            case 7: awards[0]++; break;
            case 6: awards[1]++; break;
            case 5: awards[2]++; break;
            case 4: awards[3]++; break;
            case 3: awards[4]++; break;
            case 2: awards[5]++; break;
            case 1: awards[6]++; break;
        }
    }

    for (int i = 0; i < 7; ++i) {
        cout << awards[i] << " \n"[i == 6];
    }

    return 0;
}