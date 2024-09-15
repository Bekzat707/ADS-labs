#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    string votes;
    cin >> n >> votes;

    queue<int> sakayanagi, katsuragi;

    // Fill queues with the positions of each faction's students
    for (int i = 0; i < n; ++i) {
        if (votes[i] == 'S') {
            sakayanagi.push(i);
        } else {
            katsuragi.push(i);
        }
    }

    // Simulate the process
    while (!sakayanagi.empty() && !katsuragi.empty()) {
        int s_front = sakayanagi.front();
        int k_front = katsuragi.front();
        sakayanagi.pop();
        katsuragi.pop();

        // The one with the lower index eliminates the other
        if (s_front < k_front) {
            sakayanagi.push(s_front + n);  // Moves to the next round with updated index
        } else {
            katsuragi.push(k_front + n);   // Moves to the next round with updated index
        }
    }

    // Determine the winner
    if (sakayanagi.empty()) {
        cout << "KATSURAGI" << endl;
    } else {
        cout << "SAKAYANAGI" << endl;
    }

    return 0;
}