#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<fstream>

using namespace std;

int comparison =0;
int partition(int *a,int p,int r){
    int x=a[r],temp,temp1;
    int i=p-1;
    for (int j=p; j<=r-1; j++){
       if(a[j]<=x){
           i=i+1;
           temp=a[i];
           a[i]=a[j];
           a[j]=temp;
       }
    comparison ++;
   }
    temp1=a[i+1];
    a[i+1]=a[r];
    a[r]=temp1;
    return (i+1);
}
int randomizedPartition(int *a,int low,int high){
    int pvt, n, temp;
    n = rand();

    pvt = low + n%(high-low+1);

    temp=a[pvt];
    a[pvt]=a[high];
    a[high]=temp;
    return partition(a, low, high);
}
void randomized_quicksort(int *a,int p,int r){
    int q;
    if(p<r){
    q=randomizedPartition(a,p,r);
    randomized_quicksort(a,p,q-1);
    randomized_quicksort(a,q+1,r);
    }
}
int main(){

        int size;
        cout<<"Enter the size of the array:";
        cin>>size;
        cout<<"Enter elements for array: ";
        int arr[size];
        for(int i=0; i<size; i++){
            cin>>arr[i];
        }

        randomized_quicksort(arr,0,size);
        cout<<"Sorted array is : ";
        for(int i=0; i<size; i++){
            cout<<arr[i]<<"  ";
        }

        cout<<"\nTotal number of comparisons are : "<<comparison<<endl;
    return 0;
}