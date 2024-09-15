#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, index;
    cin >> n >> index;
    vector<string> arr(n);

    // Reading input
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Adjust the index to make sure it's within the bounds of the array
    index = index % n;

    // Printing the elements from index, wrapping around if necessary
    for (int i = 0; i < n; i++) {
        cout << arr[(index + i) % n] << " ";
    }

    return 0;
}