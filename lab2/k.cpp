#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

void solve() {
    int T;
    cin >> T; // Number of test cases

    while (T--) {
        int N;
        cin >> N; // Size of the stream
        
        queue<char> q;
        unordered_map<char, int> freq; // Frequency map
        
        for (int i = 0; i < N; ++i) {
            char ch;
            cin >> ch;
            
            // Update frequency of the character
            freq[ch]++;
            
            // Add character to queue if it's the first occurrence
            if (freq[ch] == 1) {
                q.push(ch);
            }
            
            // Remove characters from the front of the queue if they are repeating
            while (!q.empty() && freq[q.front()] > 1) {
                q.pop();
            }
            
            // Output the first non-repeating character or -1 if none exists
            if (!q.empty()) {
                cout << q.front() << " ";
            } else {
                cout << "-1 ";
            }
        }
        
        cout << endl; // New line after each test case
    }
}

int main() {
    solve();
    return 0;
}