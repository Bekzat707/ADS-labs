#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> points(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> points[i];
    }
    
    sort(points.begin(), points.end());
    
    int min_diff = INT_MAX;
    
    for (int i = 1; i < n; ++i) {
        int diff = points[i] - points[i-1];
        if (diff < min_diff) {
            min_diff = diff;
        }
    }
    
    for (int i = 1; i < n; ++i) {
        int diff = points[i] - points[i-1];
        if (diff == min_diff) {
            cout << points[i-1] << " " << points[i] << " ";
        }
    }
    
    return 0;
}
