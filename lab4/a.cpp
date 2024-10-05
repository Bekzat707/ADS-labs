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

Node* insert(Node* node,int key){
    if(node==nullptr){
        return new Node(key);
    }
    else if(node->key>key){
        node->left=insert(node->left,key);
    }
    else  if (node->key<key){
        node->right=insert(node->right,key);
    }
    return node;
}
string path(Node* root,string soz){
    Node* temp=root;
    for(char element:soz){
        if(element=='L'){
            if(temp->left==nullptr){
                return "NO";
            }
            temp=temp->left;
            
        }
        else if(element=='R'){
            if(temp->right==nullptr){
                return "NO";
            }
            temp=temp->right;
        }
    }
    return "YES";
}
int main(){
    Node* root=nullptr;
    int n,k;
    cin>>n>>k;
    vector<int>sandar(n);
    vector<string>sozder(k);
    for(int i=0;i<n;i++){
        cin>>sandar[i];
       root= insert( root,sandar[i]);
    }
    for(int i=0;i<k;i++){
        cin>>sozder[i];
      cout<<  path(root,sozder[i])<<"\n";
    }
}