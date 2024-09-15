#include <iostream>
#include <deque>
using namespace std;

void find_initial_deck(int n) {
    deque<int> deck;

    // Начинаем восстанавливать колоду, начиная с карты n
    for (int i = n; i >= 1; i--) {
        deck.push_front(i);  // Вставляем карту i в начало

        // Перемещаем i карт с конца в начало (симулируем обратный процесс)
        for (int j = 0; j < i; j++) {
            int last = deck.back();  // Получаем последний элемент
            deck.pop_back();         // Удаляем его
            deck.push_front(last);   // Ставим его в начало
        }
    }

    // Выводим итоговую колоду
    for (int card : deck) {
        cout << card << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;  // Ввод количества тестов

    while (t--) {
        int n;
        cin >> n;  // Ввод размера колоды для каждого теста
        find_initial_deck(n);  // Находим и выводим начальное состояние колоды
    }

    return 0;
}