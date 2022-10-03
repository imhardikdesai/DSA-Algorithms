//edited file
#include <iostream>
#include <bits/stdc++.h>
#define MAX 10
using namespace std;
int arr[MAX],no;
void display(int n)
{
//     cout<<"-----------------------"<<endl;
//     cout<<"Arrangement No. "<<++no<<endl;
//     cout<<"-----------------------"<<endl;
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
//         cout<<"arr["<<j<<"] = "<<i_col<<endl;
//         cout<<"abs(arr[j]-i_col) = "<<arr[j]-i_col<<endl;
//         cout<<"abs(j-k_row) = "<<j-k_row<<endl;
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

