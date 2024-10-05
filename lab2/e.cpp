#include <iostream>

 
using namespace std; 
 
struct Node { 
    string name; 
    Node* next; 
     
    Node(string name) { 
        this->name = name; 
        this->next = nullptr; 
    } 
}; 
 
 
class LinkedList { 
public: 
    Node* head; 
     
    LinkedList() { 
        head = nullptr; 
    } 
    
    void add(string name) { 
        if (!head) { 
            head = new Node(name); 
        } else if (head->name != name) { 
            Node* newNode = new Node(name); 
            newNode->next = head; 
            head = newNode; 
        } 
    } 
     
 
    void printList() { 
        Node* temp = head; 
        int count = 0; 
         
        while (temp) { 
            count++; 
            temp = temp->next; 
        } 
         
        cout << "All in all: " << count << endl; 
        cout << "Students:" << endl; 
         
        temp = head; 
        while (temp) { 
            cout << temp->name << endl; 
            temp = temp->next; 
        } 
    } 
}; 
 
int main() { 
    int n; 
    cin >> n; 
     
    LinkedList list; 
    string prev = ""; 
   
    for (int i = 0; i < n; ++i) { 
        string name; 
        cin >> name; 
         
 
        if (name != prev) { 
            list.add(name); 
        } 
        prev = name; 
    } 
     
    list.printList(); 
     
    return 0; 
}