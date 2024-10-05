#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string data;
    Node* prev = nullptr;
    Node* next = nullptr;
};

class DoublyLinkedList {
    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;

public:
    // Добавление книги в начало списка
    void add_front(const string& book) {
        Node* node = new Node();
        node->data = book;

        if (!head) {
            head = tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }
        size++;
        cout << "ok" << endl;
    }

    // Добавление книги в конец списка
    void add_back(const string& book) {
        Node* node = new Node();
        node->data = book;

        if (!tail) {
            head = tail = node;
        } else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
        size++;
        cout << "ok" << endl;
    }

    // Удаление первой книги и вывод её названия
    void erase_front() {
        if (!head) {
            cout << "error" << endl;
            return;
        }
        Node* temp = head;
        cout << temp->data << endl;

        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        size--;
    }

    // Удаление последней книги и вывод её названия
    void erase_back() {
        if (!tail) {
            cout << "error" << endl;
            return;
        }
        Node* temp = tail;
        cout << temp->data << endl;

        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        size--;
    }

    // Вывод первой книги
    void front() const {
        if (!head) {
            cout << "error" << endl;
        } else {
            cout << head->data << endl;
        }
    }

    // Вывод последней книги
    void back() const {
        if (!tail) {
            cout << "error" << endl;
        } else {
            cout << tail->data << endl;
        }
    }

    // Очистка всего списка
    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        size = 0;
        cout << "ok" << endl;
    }

    // Выход из программы
    void exit() const {
        cout << "goodbye" << endl;
    }
};

int main() {
    DoublyLinkedList list;
    string command;

    while (cin >> command) {
        if (command == "add_front") {
            string book;
            cin >> book;
            list.add_front(book);
        } else if (command == "add_back") {
            string book;
            cin >> book;
            list.add_back(book);
        } else if (command == "erase_front") {
            list.erase_front();
        } else if (command == "erase_back") {
            list.erase_back();
        } else if (command == "front") {
            list.front();
        } else if (command == "back") {
            list.back();
        } else if (command == "clear") {
            list.clear();
        } else if (command == "exit") {
            list.exit();
            break;
        }
    }

    return 0;
}