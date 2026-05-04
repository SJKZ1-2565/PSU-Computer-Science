#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    string input;
    cout << "input: ";
    cin >> input;
    
    map<char, int> freq;
    
    // นับความถี่
    for (char c : input) {
        if (c >= 'a' && c <= 'z') {
            freq[c]++;
        }
    }
    
    // แสดงผล
    cout << "output: ";
    bool first = true;
    for (auto& p : freq) {
        if (!first) cout << ", ";
        cout << p.first << ":" << p.second;
        first = false;
    }
    cout << endl;
    
    return 0;
}
