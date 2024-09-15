#include <iostream>
#include <vector>
using namespace std;

// Функция для генерации простых чисел до upperLimit с использованием решета Эратосфена
vector<int> generatePrimes(int upperLimit) {
    vector<bool> isPrime(upperLimit + 1, true);
    vector<int> primes;

    isPrime[0] = isPrime[1] = false; // 0 и 1 не являются простыми числами

    for (int p = 2; p * p <= upperLimit; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= upperLimit; i += p) {
                isPrime[i] = false;
            }
        }
    }

    // Добавляем все простые числа в вектор
    for (int p = 2; p <= upperLimit; ++p) {
        if (isPrime[p]) {
            primes.push_back(p);
        }
    }

    return primes;
}

int main() {
    int n;
    cin >> n;

    // Оценим верхнюю границу для генерации простых чисел
    const int upperLimit = 8000; // Достаточный предел для поиска 1000-го простого числа

    // Генерируем простые числа
    vector<int> primes = generatePrimes(upperLimit);

    // Проверяем, достаточно ли простых чисел для получения n-го
    if (n <= primes.size()) {
        cout << primes[n - 1] << endl; // Выводим n-е простое число
    } else {
        cerr << "Error: The value of N is too large." << endl;
        return 1;
    }

    return 0;
}
