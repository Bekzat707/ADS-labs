#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    // Reading the array elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Create a map to store the frequency of each element
    unordered_map<int, int> frequency;
    for (int i = 0; i < n; i++) {
        frequency[arr[i]]++;
    }

    // Find the maximum frequency
    int maxFrequency = 0;
    for (auto& elem : frequency) {
        if (elem.second > maxFrequency) {
            maxFrequency = elem.second;
        }
    }

    // Collect elements with the highest frequency
    vector<int> mostFrequentElements;
    for (auto& elem : frequency) {
        if (elem.second == maxFrequency) {
            mostFrequentElements.push_back(elem.first);
        }
    }

    // Sort the most frequent elements in descending order
    sort(mostFrequentElements.begin(), mostFrequentElements.end(), greater<int>());

    // Output the most frequent elements
    for (int elem : mostFrequentElements) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}