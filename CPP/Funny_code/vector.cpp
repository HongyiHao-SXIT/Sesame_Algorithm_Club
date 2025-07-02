#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> websites;
    
    websites.push_back("nhooo");
    websites.push_back(".com");
    
    for (vector<string>::iterator it = websites.begin(); it != websites.end(); ++it) {
        cout << *it;
    }
    
    return 0;
}