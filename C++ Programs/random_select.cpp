#include<iostream>
#include<cstdlib>
using namespace std;

void swap(int &x, int &y){
    int tmp = x;
    x = y;
    y = tmp;
}
int partition(int a[], int p, int r){
    int x = a[r];
    int i = p-1;
    for(int j = p; j < r; j++){
        if(a[j] <= x){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[r]);
    return i+1;
}
int Randomized_Partition(int a[], int p, int r){
    int i = rand() % r + 1;
    swap(a[i], a[r]);
    return partition(a, p, r);
}
int Randomized_Select(int a[], int p, int r, int i)
{
    if(p==r)
        return a[p];
    int q = Randomized_Partition(a,p,r);
    int k = q-p+1;
    if(i == k)
        return a[q];
    else if(i < k)
        return Randomized_Select(a, p, q-1, i);
    else return Randomized_Select(a, q+1, r, i-k);
}

int main(){
    int size,i;
    cout<<"Enter the size of array :";
    cin>>size;
    int arr[20];
    cout<<"\nEnter the elements of the array :";
    for(int i=0 ; i<size; i++){
        cin>>arr[i];
    }
    cout<<"\nEnter the i for ith smallest element :";
    cin>>i;
      if(i>size)
      cout<<"The ith position does not exist.";
      else
    cout<<"\nThe "<<i<<"th smallest element in the array is : "<<Randomized_Select(arr,0,size-1,i);
    return 0;
}