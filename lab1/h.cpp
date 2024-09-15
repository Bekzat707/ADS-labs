#include <iostream>
#include <vector>
using namespace std;

void IsPrime(long long n){
    int o=0;
    bool ry=true;
    for(long long i=2;i<n;i++){
        if(n%i==0){
            ry=false;
            o++;
        }
    }
    if(o==0 && ry && n!=1){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }

    }

int main() {
    long long n;
    cin >> n;
    IsPrime(n);
}