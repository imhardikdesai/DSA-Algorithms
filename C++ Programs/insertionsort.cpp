#include<iostream>
using namespace std;

void printArray(int A[], int n){
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

void insertionSort(int A[],int n){
    int key,j;
    for(int i=1;i<n;i++){
        key=A[i];
        j=i-1;
        while(j>=0 && A[j]>key){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;
    }
}


int main(){
    int A[]={7,5,8,2,9,3,4};
    int n=7;
    insertionSort(A, n);
    printArray(A,n);
    return 0;
}
