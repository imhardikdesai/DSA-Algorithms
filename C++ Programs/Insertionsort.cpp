#include <bits/stdc++.h>
using namespace std;
void countsort(int arr[],int n){
    int maxi=-1;
    for(int i=0;i<n;i++){
        maxi=max(maxi,arr[i]);
    }
    vector<int> v(maxi+1,0);
    for(int i=0;i<n;i++){
        v[arr[i]]++;
    }
    int j=0;
    for(int i=0;i<=maxi;i++){
        while(v[i]>0){
            arr[i]=i;
            v[i]--;
            j++;
        }
    }
}
int main() {
int arr[]={1,5,3,9,7,5,6,8,4,1,9};
int n=sizeof(arr)/sizeof(arr[0]);
countsort(arr,n);
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
	return 0;
}
