#include <iostream>
#include <stack>
using namespace std;

int main() {
    string n;
    cin >> n;  // Ввод строки
    stack<char> letters;

    // Проходим по каждому символу строки
    for (char elem : n) {
        if (!letters.empty() && elem == letters.top()) {
            letters.pop();  // Если символ совпадает с верхним, удаляем его
        } else {
            letters.push(elem);  // Иначе добавляем символ в стек
        }
    }

    // Если стек пуст, значит последовательность сбалансирована
    if (letters.empty()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}