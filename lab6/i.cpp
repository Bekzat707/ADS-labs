#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string str;
    cin>>str;
    vector<string> vec(size(str));
    for( char c:str){
        vec.push_back(string(1,c));
    }
    sort(vec.begin(),vec.end());

    for(string c: vec){
        cout<<c;
    }
}