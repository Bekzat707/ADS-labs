#include <bits/stdc++.h>
using namespace std;

// Функция для проверки, можно ли покрыть наш к элемент скотов с помощи л строрны квадратиков
bool solution(int L, int K, vector<pair<int, int>>& sandar) {
    int count = 0;
    for (const auto& pasture : sandar) {
        int x2 = pasture.first;
        int y2 = pasture.second;
        if (x2 <= L && y2 <= L) {
            count++;
        }
        if (count >= K) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    

    vector<pair<int, int>> pastures(n);
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        pastures[i] = {x2, y2};
    }
    
    int left = 1;
    int right = 1e9;
    int result = 0;
    

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (solution(mid, k, pastures)) {
            result = mid; // Если можем покрыть, пытаемся найти меньшее значение
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << result << endl;
    return 0;
}