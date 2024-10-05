#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;  // Number of competitors
    vector<int> powers(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> powers[i];  // Powers of the competitors
    }

    int rounds;
    cin >> rounds;  // Number of rounds
    vector<int> markPowers(rounds);
    
    for (int i = 0; i < rounds; ++i) {
        cin >> markPowers[i];  // Mark's power in each round
    }

    // Sort the competitors' powers
    sort(powers.begin(), powers.end());

    // Prepare to store results
    for (int markPower : markPowers) {
        // Find the upper bound of markPower in the sorted powers
        auto it = upper_bound(powers.begin(), powers.end(), markPower);
        int count = it - powers.begin();  // Number of competitors he can defeat
        
        // Calculate the sum of the powers he can defeat
        int sum = 0;
        for (int i = 0; i < count; ++i) {
            sum += powers[i];
        }

        // Output the result for this round
        cout << count << " " << sum << endl;
    }

    return 0;
}
