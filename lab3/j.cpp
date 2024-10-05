
// Решение для этой задачи в находим тут самую минимальную время за которое может все перенести 
#include <bits/stdc++.h>
using namespace std;
int main(){
     ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,h;
    cin>>n>>h;
    vector<int>san(n);
    
    for(int i=0;i<n;i++){
        cin>>san[i];
    }
    int left=1;
    int right=*max_element(san.begin(),san.end());
    int result=0;
    while(left<=right){
        int mid=(left+right)/2;// находим число типа [3,4,11,2]  right=11 left=1 mid=6
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=(san[i]+mid-1)/mid;// 3+6-1/6+4+6-1/6+11+6-1/6+2+6-1/6 если это число меньше чем наше время то 
// делаем так записиваем наш мин в резалт и смотрим если есть еще меньше и так дальше
        }
        if(sum<=h){
            result=mid;
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    cout<<result;

}