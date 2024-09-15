#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int target,index=0;
    cin>>target;
    int min_distance=abs(arr[0]-target);
    for(int i=1;i<n;i++){
        int temp=abs(arr[i]-target);
        if(temp<min_distance){
            min_distance=temp;
            index=i;
        }
    }
cout<<index;
}