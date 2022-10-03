#include <iostream>
#include <bits/stdc++.h>
#define MAX 10
using namespace std;
int arr[MAX],no;
void display(int n)
{
    cout<<"-----------------------"<<endl;
    cout<<"Arrangement No. "<<++no<<endl;
    cout<<"-----------------------"<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(arr[i]!=j)
            {
                cout<<" _ ";
            }
            else
            {
                cout<<" Q ";
            }
        }
        cout<<endl;
    }
}
bool can_place(int k_row,int i_col)
{
    for(int j=1;j<=k_row-1;j++)
    {
        cout<<"arr["<<j<<"] = "<<i_col<<endl;
        cout<<"abs(arr[j]-i_col) = "<<arr[j]-i_col<<endl;
        cout<<"abs(j-k_row) = "<<j-k_row<<endl;
        if(arr[j]==i_col||(abs(arr[j]-i_col)==abs(j-k_row)))
        {
            cout<<"returned false"<<endl;
            return false;
        }
    }
    cout<<"returned true"<<endl;
    return true;
}
void n_queen(int k,int n)
{
    for(int i=1;i<=n;i++)
    {
        cout<<"i = "<<i<<" , k = "<<k<<endl;
        
        if(can_place(k,i))
        {
            arr[k]=i;
            if(k==n)
            {
                display(n);
            }
            else
            {
                cout<<"k+1 = "<<k+1<<endl;
                n_queen(k+1,n);
            }
        }
    }
}

int main() {
   
int n=4;
n_queen(1,n);
return 0;
}

/*
/tmp/jHP1lGqCft.o
i = 1 , k = 1
returned true
k+1 = 2
i = 1 , k = 2
arr[1] = 1
abs(arr[j]-i_col) = 0
abs(j-k_row) = -1
returned false
i = 2 , k = 2
arr[1] = 2
abs(arr[j]-i_col) = -1
abs(j-k_row) = -1
returned false
i = 3 , k = 2
arr[1] = 3
abs(arr[j]-i_col) = -2
abs(j-k_row) = -1
returned true
k+1 = 3
i = 1 , k = 3
arr[1] = 1
abs(arr[j]-i_col) = 0
abs(j-k_row) = -2
returned false
i = 2 , k = 3
arr[1] = 2
abs(arr[j]-i_col) = -1
abs(j-k_row) = -2
arr[2] = 2
abs(arr[j]-i_col) = 1
abs(j-k_row) = -1
returned false
i = 3 , k = 3
arr[1] = 3
abs(arr[j]-i_col) = -2
abs(j-k_row) = -2
returned false
i = 4 , k = 3
arr[1] = 4
abs(arr[j]-i_col) = -3
abs(j-k_row) = -2
arr[2] = 4
abs(arr[j]-i_col) = -1
abs(j-k_row) = -1
returned false
i = 4 , k = 2
arr[1] = 4
abs(arr[j]-i_col) = -3
abs(j-k_row) = -1
returned true
k+1 = 3
i = 1 , k = 3
arr[1] = 1
abs(arr[j]-i_col) = 0
abs(j-k_row) = -2
returned false
i = 2 , k = 3
arr[1] = 2
abs(arr[j]-i_col) = -1
abs(j-k_row) = -2
arr[2] = 2
abs(arr[j]-i_col) = 2
abs(j-k_row) = -1
returned true
k+1 = 4
i = 1 , k = 4
arr[1] = 1
abs(arr[j]-i_col) = 0
abs(j-k_row) = -3
returned false
i = 2 , k = 4
arr[1] = 2
abs(arr[j]-i_col) = -1
abs(j-k_row) = -3
arr[2] = 2
abs(arr[j]-i_col) = 2
abs(j-k_row) = -2
returned false
i = 3 , k = 4
arr[1] = 3
abs(arr[j]-i_col) = -2
abs(j-k_row) = -3
arr[2] = 3
abs(arr[j]-i_col) = 1
abs(j-k_row) = -2
arr[3] = 3
abs(arr[j]-i_col) = -1
abs(j-k_row) = -1
returned false
i = 4 , k = 4
arr[1] = 4
abs(arr[j]-i_col) = -3
abs(j-k_row) = -3
returned false
i = 3 , k = 3
arr[1] = 3
abs(arr[j]-i_col) = -2
abs(j-k_row) = -2
returned false
i = 4 , k = 3
arr[1] = 4
abs(arr[j]-i_col) = -3
abs(j-k_row) = -2
arr[2] = 4
abs(arr[j]-i_col) = 0
abs(j-k_row) = -1
returned false
i = 2 , k = 1
returned true
k+1 = 2
i = 1 , k = 2
arr[1] = 1
abs(arr[j]-i_col) = 1
abs(j-k_row) = -1
returned false
i = 2 , k = 2
arr[1] = 2
abs(arr[j]-i_col) = 0
abs(j-k_row) = -1
returned false
i = 3 , k = 2
arr[1] = 3
abs(arr[j]-i_col) = -1
abs(j-k_row) = -1
returned false
i = 4 , k = 2
arr[1] = 4
abs(arr[j]-i_col) = -2
abs(j-k_row) = -1
returned true
k+1 = 3
i = 1 , k = 3
arr[1] = 1
abs(arr[j]-i_col) = 1
abs(j-k_row) = -2
arr[2] = 1
abs(arr[j]-i_col) = 3
abs(j-k_row) = -1
returned true
k+1 = 4
i = 1 , k = 4
arr[1] = 1
abs(arr[j]-i_col) = 1
abs(j-k_row) = -3
arr[2] = 1
abs(arr[j]-i_col) = 3
abs(j-k_row) = -2
arr[3] = 1
abs(arr[j]-i_col) = 0
abs(j-k_row) = -1
returned false
i = 2 , k = 4
arr[1] = 2
abs(arr[j]-i_col) = 0
abs(j-k_row) = -3
returned false
i = 3 , k = 4
arr[1] = 3
abs(arr[j]-i_col) = -1
abs(j-k_row) = -3
arr[2] = 3
abs(arr[j]-i_col) = 1
abs(j-k_row) = -2
arr[3] = 3
abs(arr[j]-i_col) = -2
abs(j-k_row) = -1
returned true
-----------------------
Arrangement No. 1
-----------------------
 _  Q  _  _ 
 _  _  _  Q 
 Q  _  _  _ 
 _  _  Q  _ 
i = 4 , k = 4
arr[1] = 4
abs(arr[j]-i_col) = -2
abs(j-k_row) = -3
arr[2] = 4
abs(arr[j]-i_col) = 0
abs(j-k_row) = -2
returned false
i = 2 , k = 3
arr[1] = 2
abs(arr[j]-i_col) = 0
abs(j-k_row) = -2
returned false
i = 3 , k = 3
arr[1] = 3
abs(arr[j]-i_col) = -1
abs(j-k_row) = -2
arr[2] = 3
abs(arr[j]-i_col) = 1
abs(j-k_row) = -1
returned false
i = 4 , k = 3
arr[1] = 4
abs(arr[j]-i_col) = -2
abs(j-k_row) = -2
returned false
i = 3 , k = 1
returned true
k+1 = 2
i = 1 , k = 2
arr[1] = 1
abs(arr[j]-i_col) = 2
abs(j-k_row) = -1
returned true
k+1 = 3
i = 1 , k = 3
arr[1] = 1
abs(arr[j]-i_col) = 2
abs(j-k_row) = -2
returned false
i = 2 , k = 3
arr[1] = 2
abs(arr[j]-i_col) = 1
abs(j-k_row) = -2
arr[2] = 2
abs(arr[j]-i_col) = -1
abs(j-k_row) = -1
returned false
i = 3 , k = 3
arr[1] = 3
abs(arr[j]-i_col) = 0
abs(j-k_row) = -2
returned false
i = 4 , k = 3
arr[1] = 4
abs(arr[j]-i_col) = -1
abs(j-k_row) = -2
arr[2] = 4
abs(arr[j]-i_col) = -3
abs(j-k_row) = -1
returned true
k+1 = 4
i = 1 , k = 4
arr[1] = 1
abs(arr[j]-i_col) = 2
abs(j-k_row) = -3
arr[2] = 1
abs(arr[j]-i_col) = 0
abs(j-k_row) = -2
returned false
i = 2 , k = 4
arr[1] = 2
abs(arr[j]-i_col) = 1
abs(j-k_row) = -3
arr[2] = 2
abs(arr[j]-i_col) = -1
abs(j-k_row) = -2
arr[3] = 2
abs(arr[j]-i_col) = 2
abs(j-k_row) = -1
returned true
-----------------------
Arrangement No. 2
-----------------------
_  _  Q  _ 
 Q  _  _  _ 
 _  _  _  Q 
 _  Q  _  _ 
i = 3 , k = 4
arr[1] = 3
abs(arr[j]-i_col) = 0
abs(j-k_row) = -3
returned false
i = 4 , k = 4
arr[1] = 4
abs(arr[j]-i_col) = -1
abs(j-k_row) = -3
arr[2] = 4
abs(arr[j]-i_col) = -3
abs(j-k_row) = -2
arr[3] = 4
abs(arr[j]-i_col) = 0
abs(j-k_row) = -1
returned false
i = 2 , k = 2
arr[1] = 2
abs(arr[j]-i_col) = 1
abs(j-k_row) = -1
returned false
i = 3 , k = 2
arr[1] = 3
abs(arr[j]-i_col) = 0
abs(j-k_row) = -1
returned false
i = 4 , k = 2
arr[1] = 4
abs(arr[j]-i_col) = -1
abs(j-k_row) = -1
returned false
i = 4 , k = 1
returned true
k+1 = 2
i = 1 , k = 2
arr[1] = 1
abs(arr[j]-i_col) = 3
abs(j-k_row) = -1
returned true
k+1 = 3
i = 1 , k = 3
arr[1] = 1
abs(arr[j]-i_col) = 3
abs(j-k_row) = -2
arr[2] = 1
abs(arr[j]-i_col) = 0
abs(j-k_row) = -1
returned false
i = 2 , k = 3
arr[1] = 2
abs(arr[j]-i_col) = 2
abs(j-k_row) = -2
returned false
i = 3 , k = 3
arr[1] = 3
abs(arr[j]-i_col) = 1
abs(j-k_row) = -2
arr[2] = 3
abs(arr[j]-i_col) = -2
abs(j-k_row) = -1
returned true
k+1 = 4
i = 1 , k = 4
arr[1] = 1
abs(arr[j]-i_col) = 3
abs(j-k_row) = -3
returned false
i = 2 , k = 4
arr[1] = 2
abs(arr[j]-i_col) = 2
abs(j-k_row) = -3
arr[2] = 2
abs(arr[j]-i_col) = -1
abs(j-k_row) = -2
arr[3] = 2
abs(arr[j]-i_col) = 1
abs(j-k_row) = -1
returned false
i = 3 , k = 4
arr[1] = 3
abs(arr[j]-i_col) = 1
abs(j-k_row) = -3
arr[2] = 3
abs(arr[j]-i_col) = -2
abs(j-k_row) = -2
returned false
i = 4 , k = 4
arr[1] = 4
abs(arr[j]-i_col) = 0
abs(j-k_row) = -3
returned false
i = 4 , k = 3
arr[1] = 4
abs(arr[j]-i_col) = 0
abs(j-k_row) = -2
returned false
i = 2 , k = 2
arr[1] = 2
abs(arr[j]-i_col) = 2
abs(j-k_row) = -1
returned true
k+1 = 3
i = 1 , k = 3
arr[1] = 1
abs(arr[j]-i_col) = 3
abs(j-k_row) = -2
arr[2] = 1
abs(arr[j]-i_col) = 1
abs(j-k_row) = -1
returned false
i = 2 , k = 3
arr[1] = 2
abs(arr[j]-i_col) = 2
abs(j-k_row) = -2
returned false
i = 3 , k = 3
arr[1] = 3
abs(arr[j]-i_col) = 1
abs(j-k_row) = -2
arr[2] = 3
abs(arr[j]-i_col) = -1
abs(j-k_row) = -1
returned false
i = 4 , k = 3
arr[1] = 4
abs(arr[j]-i_col) = 0
abs(j-k_row) = -2
returned false
i = 3 , k = 2
arr[1] = 3
abs(arr[j]-i_col) = 1
abs(j-k_row) = -1
returned false
i = 4 , k = 2
arr[1] = 4
abs(arr[j]-i_col) = 0
abs(j-k_row) = -1
returned false
*/
