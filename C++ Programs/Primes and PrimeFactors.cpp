/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;
bool isPrime(int n){
    if(n==1){
        return false;
    }
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
        return true;
}
//OPTIMIZED APPROACH
void PrimeFactors(int n){
    if(n<=1){
        return;
    }
    for(int i=2;i*i<=n;i++){
        
            while(n%i==0){
                cout<<i<<" ";
            n=n/i;
            
            }
    }
            if(n>1){
                cout<<n<<" ";
            }
}
//   NAIVE APPROACH

// void PrimeFactors(int n){
//     if(n==1){
//         cout<<"0"<<endl;
//     }
//     for(int i=2;i<n;i++){
//         if(isPrime){
//             int x=i;
//             while(n%x==0){
//                 cout<<i<<" ";
//                 x=x*i;
//             }
//         }
//     }
// }
int main()
{
int n;
cin>>n;
PrimeFactors(n);


    return 0;
}
