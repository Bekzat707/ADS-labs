#include <iostream>
using namespace std;

// Узел списка
class Node {
public:
    int data;
    Node* next;
    
    Node(int value) : data(value), next(nullptr) {}
};

// Односвязный список
class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    // Добавление элемента в конец списка
    void add_back(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Функция для поиска подмассива с максимальной суммой
    int findMaxSum() {
        if (!head) return 0;  // Если список пуст

        int current_sum = head->data;
        int max_sum = head->data;
        
        Node* temp = head->next;
        
        while (temp) {
            current_sum = max(temp->data, current_sum + temp->data);
            max_sum = max(max_sum, current_sum);
            temp = temp->next;
        }
        
        return max_sum;
    }
};

int main() {
    LinkedList list;
    int n, value;
    
    // Ввод данных
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> value;
        list.add_back(value);
    }

    // Поиск и вывод максимальной суммы
    cout << list.findMaxSum() << endl;

    return 0;
}