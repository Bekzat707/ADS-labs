#include <bits/stdc++.h>
using namespace std;


struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int item) {
        key = item;
        left = right = nullptr;
    }
};


Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }
    if (root->key > key) {
        root->left = insert(root->left, key);
    } else if (root->key < key) {
        root->right = insert(root->right, key);
    }
    return root;
}


int Result(Node* root) {
    int cnt = 0;
    if (root == nullptr) {
        return 0;
    }
    if (root->left != nullptr && root->right != nullptr) {
        cnt = 1;
    }

  
    cnt += Result(root->left);
    cnt += Result(root->right);
    return cnt;
}

int main() {
    Node* root = nullptr;
    int n;
    cin >> n;
    vector<int> sandar(n);
    

    for (int i = 0; i < n; i++) {
        cin >> sandar[i];
        root = insert(root, sandar[i]);  
    }
    
    cout << Result(root) << endl;
    
    return 0;
}