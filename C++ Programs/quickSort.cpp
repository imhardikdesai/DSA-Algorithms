#include<iostream>
using namespace std;
void swap(int arr[],int a,int b)
{
    int t=arr[a];
    arr[a]=arr[b];
    arr[b]=t;
}
int partition(int arr[],int low,int high)
{
    int i=low-1;
    int pivot=arr[high];
    for (int j=low;j<high;j++)
    {
        if (arr[j]<pivot)
        {
            i++;
            swap(arr,i,j);
        }
    }
    swap(arr,i+1,high);
    return(i+1);
}
int quickSort(int arr[],int low,int high)
{
    if (low<high)
    {
        int par=partition(arr,low,high);
        quickSort(arr,low,par-1);
        quickSort(arr,par+1,high);
    }
    return 0;
}
void display(int arr[],int high)
{
    cout<<"\nSorted array is : ";
    for (int i=0;i<=high;i++)
        cout<<arr[i]<<" ";
}
int main()
{
    int arr[10]={1,2,3,10,23,6,45,11,9,34};
    int size=sizeof(arr)/sizeof(arr[0]);
    int h=size-1;
    int l=3;
    quickSort(arr,l,h);
    display(arr,h);
    return 0;
}