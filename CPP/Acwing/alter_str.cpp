#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string s, a, b;
    
    getline(cin, s);
    cin >> a >> b;
    
    vector<string> words;
    string word;
    stringstream ss(s);
    
    while (ss >> word) {
        words.push_back(word);
    }
    
    for (auto& w : words) {
        if (w == a) {
            w = b;
        }
    }

    for (int i = 0; i < words.size(); ++i) {
        if (i != 0) cout << " ";
        cout << words[i];
    }
    cout << endl;
    
    return 0;
}