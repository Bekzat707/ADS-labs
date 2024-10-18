#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> rows(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> rows[i][j];
        }
    }

    sort(rows.begin(), rows.end(), [](const vector<int>& a, const vector<int>& b) {
        int sum_a = accumulate(a.begin(), a.end(), 0);
        int sum_b = accumulate(b.begin(), b.end(), 0);
        if (sum_a != sum_b) {
            return sum_a > sum_b;
        }
        return a < b;
    });

    for (const auto& row : rows) {
        for (int i = 0; i < m; i++) {
            cout << row[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
