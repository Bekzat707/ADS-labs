#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t; // Number of elements to search
    cin >> t;
    
    vector<int> elements(t); // Elements to search for
    for (int i = 0; i < t; ++i) {
        cin >> elements[i];
    }
    
    int n, m; // Dimensions of the snake array
    cin >> n >> m;
    
    vector<vector<int>> snakeArray(n, vector<int>(m)); // The snake array
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> snakeArray[i][j];
        }
    }
    
    for(int elem : elements) {
        bool found = false;
        for(int i = 0; i < n; i++) {
            // Определяем направление для текущей строки
            if (i % 2 == 0) { // Четная строка: справа налево
                for (int j = m - 1; j >= 0; j--) {
                    if (snakeArray[i][j] == elem) {
                        cout << i << " " << j << endl;
                        found = true;
                        break;
                    }
                }
            } else { // Нечетная строка: слева направо
                for (int j = 0; j < m; j++) {
                    if (snakeArray[i][j] == elem) {
                        cout << i << " " << j << endl;
                        found = true;
                        break;
                    }
                }
            }
            if (found) break;
        }
        if (!found) {
            cout << "-1" << endl;
        }
    }
    
    return 0;
}
