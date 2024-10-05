#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>v;
int easy(int target){
    int l=0;
    int r=v.size()-1;
    int res=-1; // индекс этих чисел 
    while(l<=r){
        int mid=(l+r)/2;
        if(v[mid]<=target){
            res=mid;
            l=mid+1;
        }
        else{
            r=mid-1;

        }
    }
    return res+1;
    
}

int answer(int l,int r){
    return easy(r)-easy(l-1);
}
int main(){
     ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }

    sort(v.begin(),v.end());
    while(k--){
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
         if (r2 < l1 || r1 < l2) {
            // Если диапазоны не пересекаются тоесть когда не бывают таких примеров [1,4],[3,6]
            int res = answer(l1, r1) + answer(l2, r2);
            cout << res << '\n';
        } else {
            // Если диапазоны пересекаются, находим объединенный диапазон
            int mini = min(l1, l2); //[1,4]=min[1]
            int maxi = max(r1, r2);//[3,6]=max[6] 
                                // itog = [1,6];
            cout << answer(mini, maxi) << '\n';
        }
    }
    }
