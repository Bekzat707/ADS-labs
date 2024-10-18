#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string line;
        getline(cin, line);

        vector<string> strings;
        stringstream ss(line);
        string word;

        while (ss >> word) {
            strings.push_back(word);
        }

        stable_sort(strings.begin(), strings.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        for (int i = 0; i < strings.size(); i++) {
            if (i > 0) cout << " ";
            cout << strings[i];
        }
        cout << endl;
    }

    return 0;
}
