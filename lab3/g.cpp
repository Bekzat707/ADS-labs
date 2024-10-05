#include <bits/stdc++.h>
using namespace std;
bool check(int mid, int f, vector<int>& v) {
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += (v[i] + mid - 1) / mid;
    }
    return sum <= f;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int l = 1;
    int r = *max_element(v.begin(), v.end());
    

    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid, m, v)) {
            r = mid; 
        } else {
            l = mid + 1; 
        }
    }

    cout << l << endl; 

    return 0;
}