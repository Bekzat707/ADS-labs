#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& vec,int l,int r,int m){
    int n1=m-l+1;
    int n2=r-m;
    vector<int>left(n1);
    vector<int>right(n2);
    for (int i = 0; i < n1; i++) {
        left[i] = vec[l + i];
    }
    for (int j = 0; j < n2; j++) {
        right[j] = vec[m + 1 + j];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            vec[k] = left[i];
            i++;
        } else {
            vec[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        vec[k] = left[i];
        i++;
        k++;
    }
    while (j < n2) {
        vec[k] = right[j];
        j++;
        k++;
    }
}

void mergesort(vector<int>& vec,int l,int r){

    if(l<r){
       int m = l + (r-l)/2;
        mergesort(vec,l,m);

        mergesort(vec,m+1,r);

        merge(vec,l,r,m);

    }
    

}
int main(){
    int a,b;
    cin>>a;
    vector<int>vec(a);
    for(int i=0;i<a;i++){
        cin>>vec[i];
    }
    cin>>b;
    vector<int>vec2(b);
    for(int j=0;j<b;j++){
        cin>>vec2[j];
    }
    for(int i:vec2){
        vec.push_back(i);
    } 
    int r=vec.size()-1;
    mergesort(vec,0,r);

    for (int i = 0; i <vec.size() ; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}