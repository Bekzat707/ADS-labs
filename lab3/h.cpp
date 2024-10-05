#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    
    vector<int> blocks(n);
    vector<long long> mistakes(m);

    for (int i = 0; i < n; i++) {
        cin >> blocks[i];
    }
// [5,10,15]
    for (int i = 0; i < m; i++) {
        cin >> mistakes[i];
    }

    vector<long long> P(n);
    P[0] = blocks[0];
    for (int i = 1; i < n; i++) {
        P[i] = P[i - 1] + blocks[i];// Создаем массив с сум [5,12,18] 
    }

    
    for (int i = 0; i < m; i++) {
        long long line = mistakes[i]; 
        for (int j = 0; j < n; j++) {
            if (line <= P[j]) { // Сравниваем элементы тоесть 5<=5 да тоесть 1 идем дальше 10<=5 нет идем дальше 10<=12 да 2 идем дальше 15<=5 нет 15<=10 нет 15<=18 да j=2 answer 2+1=3
                cout << j + 1 << endl; // Нумерация блоков начинается с 1
                break;
            }
        }
    }

   
}