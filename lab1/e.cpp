#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int>first,second;
    int a,b;
    for(int i=0;i<5;i++){
        cin>>a;
        first.push(a);
    }
    for(int i=0;i<5;i++){
        cin>>b;
        second.push(b);
    }
    int cnt=0;
    int cntmax=1000000;
    int nu=0;
    int bo=0;
    while(!first.empty() && !second.empty() && cnt<cntmax){
        int a=first.front();
        int b=second.front();
        first.pop();
        second.pop();
        
        if((a==0 && b==9)||( a>b && !(a==9 && b==0))){
            first.push(a);
            first.push(b);
         }
        else{
            second.push(a);
            second.push(b);
        }
        cnt++;
    }
    if(cnt>=cntmax){
        cout<<"blin nichya";

    }
    else if(first.empty()){
        cout<<"Nursik "<<cnt;
    }
    else{
        cout<<"Boris "<<cnt;
    }
}