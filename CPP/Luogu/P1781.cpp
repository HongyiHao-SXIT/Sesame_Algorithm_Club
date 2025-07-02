#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Candidate {
    int id;
    string votes;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Candidate> candidates(n);
    
    for (int i = 0; i < n; ++i) {
        candidates[i].id = i + 1;
        cin >> candidates[i].votes;
    }

    auto compare = [](const Candidate& a, const Candidate& b) {
        if (a.votes.length() != b.votes.length()) {
            return a.votes.length() > b.votes.length();
        }
        return a.votes > b.votes;
    };

    sort(candidates.begin(), candidates.end(), compare);

    cout << candidates[0].id << '\n';
    cout << candidates[0].votes << endl;

    return 0;
}