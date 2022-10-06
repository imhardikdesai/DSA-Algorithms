#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    long long trappingWater(int arr[], int n){
        long res = 0;
        int lmax[n],rmax[n];
        lmax[0]=arr[0];
        for(int i=1;i<n;i++)
            lmax[i]=max(arr[i],lmax[i-1]);
        rmax[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)
            rmax[i]=max(arr[i],rmax[i+1]);
        for(int i=1;i<n-1;i++)
            res= res+(min(lmax[i],rmax[i])-arr[i]);
    return res;
    }
};
int main(){
    
    int t;
    cin >> t;//test cases
    while(t--){
        int n;//size of array
        cin >> n;
        int a[n];
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        cout << obj.trappingWater(a, n) << endl;//calling function
    }
    return 0;
}  
