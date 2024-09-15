#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Функция для обработки строки с учётом символа #
string processString(const string& s) {
    stack<char> result;
    for (char ch : s) {
        if (ch == '#') {
            if (!result.empty()) {
                result.pop();  // Удаляем последний символ, если есть
            }
        } else {
            result.push(ch);  // Добавляем символ в стек
        }
    }
    
    // Превращаем стек в строку
    string processed;
    while (!result.empty()) {
        processed = result.top() + processed;  // Добавляем элементы в строку
        result.pop();
    }
    
    return processed;
}

int main() {
    string s1, s2;
    
    // Чтение двух строк через пробел
    cin >> s1 >> s2;
    
    // Обрабатываем обе строки и сравниваем
    if (processString(s1) == processString(s2)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}