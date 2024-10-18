#include <iostream>
#include <vector>
using namespace std;

char find_balanced_char(const vector<char>& arr, char target) {
    int n = arr.size();
    int left = 0, right = n - 1;
    char result = arr[0]; // Assume the smallest character will be the answer if nothing is found

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] > target) {
            result = arr[mid];  // Potential answer, but let's continue to search in the left half
            right = mid - 1;
        } else {
            left = mid + 1;  // Search in the right half
        }
    }
    
    return result;
}

int main() {
    int n;
    cin >> n;
    
    vector<char> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    char target;
    cin >> target;
    
    cout << find_balanced_char(arr, target) << endl;

    return 0;
}