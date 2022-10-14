#include<iostream>
using namespace std;

int Binary_Search_Recursion(int a[],int low,int high,int key){

    int mid=(low+high)/2;
    if(low>high)
    return -1;

    if(a[mid]==key)
    return mid;

    else if(a[mid]>key)
        return Binary_Search_Recursion( a, low, mid-1,  key);

    else
    return Binary_Search_Recursion(a, mid+1, high, key);


}

int main(){

    int size;
    cin>>size;
    int a[size];

    for(int i=0;i<size;i++){
        cin>>a[i];
    }
    int key;
    cin>>key;

    int ans = Binary_Search_Recursion(a,0,size-1,key);

    if(ans==-1){
        cout<<"Not Found"<<endl;
    }

    else{
        cout<<key<<" Found at "<<ans+1<<endl;
    }

        return 0;
}