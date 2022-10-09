#include <iostream>
using namespace std;
int partition(int *a,int l,int r)
{
 int pivot=a[r];
 int j=l-1;
 for(int i=l;i<=r-1;i++)
 {
    if(pivot>a[i])
    {
      j++;
      swap(a[i],a[j]);
    }
 }
    swap(a[j+1],a[r]);
    return j+1; 
}
void quicksort(int *a,int l,int r)
{
 if(l>r)
 return;
 else{
    int p=partition(a,l,r);
    quicksort(a,l,p-1);
    quicksort(a,p+1,r);
 }
}
int main()
{
    int n,l=0;
    cin>>n;
    int *a=new int(n);
    int i;
    for(i=0;i<n;i++)
    cin>>a[i];
    quicksort(a,l,n-1);
     for(i=0;i<n;i++)
    cout<<a[i];
    return 0;
}