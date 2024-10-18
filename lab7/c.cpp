#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> first(n), second(m);
    
    // Вводим массивы
    for (int i = 0; i < n; i++) {
        cin >> first[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> second[i];
    }
    
    // Сортируем массивы
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());
    
    // Используем два указателя для нахождения пересечений
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (first[i] == second[j]) {
            cout << first[i] << " ";  // Выводим общий элемент
            i++;
            j++;
        } else if (first[i] < second[j]) {
            i++;  // Двигаем указатель первого массива
        } else {
            j++;  // Двигаем указатель второго массива
        }
    }

    cout << endl;
    return 0;
}