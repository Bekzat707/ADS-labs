#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

bool canDivide(const vector<int>& ghouls, int maxGhouls, int k) {
    int currentSum = 0;
    int blockCount = 1; // Start with one block

    for (int ghoul : ghouls) {
        if (currentSum + ghoul > maxGhouls) {
            blockCount++; // Need a new block
            currentSum = ghoul; // Start new block with current house
            if (blockCount > k) {
                return false; // Too many blocks
            }
        } else {
            currentSum += ghoul; // Add to current block
        }
    }
    return true;
}

int findMinimumMaxGhouls(int n, int k, const vector<int>& ghouls) {
    int left = *max_element(ghouls.begin(), ghouls.end()); // The largest single house
    int right = accumulate(ghouls.begin(), ghouls.end(), 0); // The sum of all houses

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (canDivide(ghouls, mid, k)) {
            right = mid; // Try for a smaller max
        } else {
            left = mid + 1; // Increase the max
        }
    }

    return left; // This will be the minimum possible max ghouls
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> ghouls(n);
    for (int i = 0; i < n; i++) {
        cin >> ghouls[i];
    }

    cout << findMinimumMaxGhouls(n, k, ghouls) << endl;

    return 0;
}
