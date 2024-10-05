#include <iostream>
#include <vector>

using namespace std;
int binarysearch(int arr[],int size,int t ){
    int left=0;
    int right=size-1;
    while(left<=right){
        int mid=left+(right-left)/2;

        if(arr[mid]==t){
            return mid;
        }
        if(arr[mid]>t){
            right=mid-1;
        }
        else{
            left=mid+1;
        }
        
    }
return -1;
}

int main(){
    int n,t;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>t;
    int result=binarysearch(arr ,n,t);
    if(result == -1){
        cout<<"No";
    }
    else{
        cout<<"Yes";
    }
    return 0;
}