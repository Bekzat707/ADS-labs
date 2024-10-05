#include <bits/stdc++.h>
using namespace std;
 struct Node{
    int key;
    Node* left;
    Node* right;
    Node(int item){
        key=item;
        left=right=nullptr;
    }
};
Node* insert(Node* root,int key){
    if(root==nullptr){
        return new Node(key);
    }
    else if(root->key>key){
        root->left=insert(root->left,key);
    }
    else if(root->key<key){
        root->right=insert(root->right,key);
    }
    return root;
}
int Result(Node* root,int &cnt){
    if(root==nullptr){
        return 0;
    }
    int  leftside=Result(root->left,cnt);
    int rightside=Result(root->right,cnt);
    cnt=max(cnt,rightside+leftside);
    return max(leftside,rightside)+1;

}
int main(){
    Node* root=nullptr;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int san;
        cin>>san;
        root=insert(root,san);
    }
    int cnt=0;
    Result(root,cnt);
    cout<<cnt+1;
}