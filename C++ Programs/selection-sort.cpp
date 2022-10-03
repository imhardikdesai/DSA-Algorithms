#include <bits/stdc++.h>
using namespace std;
void selectionsort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int k=i;
        for(int j=i;j<n;j++){
          if(arr[j]<arr[k])  
             k=j;
        }
        swap(arr[i],arr[k]);
    }
}
void printarr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
        cout<<endl;
    }
}
int main() {
int arr[]={64, 25, 12, 22, 11};
int n=sizeof(arr)/sizeof(arr[0]);
selectionsort(arr,n);
printarr(arr,n);
	return 0;
}
