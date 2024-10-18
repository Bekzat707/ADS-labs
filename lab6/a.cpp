#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    string str;

    cin >> n >> str;

    if (str.length() == n) {
        vector<char> vec;
        vector<char> vecs;

        for (char c : str) {
            if (c == 'e' || c == 'a' || c == 'i' || c == 'o' || c == 'u') {
                vecs.push_back(c);
            } else {
                vec.push_back(c);
            }
        }

        sort(vec.begin(), vec.end());
        sort(vecs.begin(), vec.end());

        vecs.insert(vecs.end(), vec.begin(), vec.end());

        for (char c : vecs) {
            cout << c;
        }
        cout << endl;
    }

    return 0;
}
