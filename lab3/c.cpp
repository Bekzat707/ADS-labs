#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    for (int i = 0; i < q; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        
        int count = 0;
        for (int j = 0; j < n; ++j) {
            if ((arr[j] >= a && arr[j] <= b) || (arr[j] >= c && arr[j] <= d)) {
                count++;
            }
        }
        cout << count << endl;
    }

    return 0;
}
