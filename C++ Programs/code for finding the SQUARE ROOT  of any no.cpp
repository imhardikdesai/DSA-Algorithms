
             //CODE FOR FINDING THE SQUARE ROOT OF ANY NO. 

#include<iostream>
using namespace std;

 long long int sqrtInteger(int n) {     //FUNCTION FOR FINDING THE INTERGER PART OF SQUARE ROOT
        
        int s = 0;
        int e = n;
        long long int mid = s + (e-s)/2;
        
        long long int ans = -1;
        while(s<=e) {
            
            long long int square = mid*mid;
            
            if(square == n)
                return mid;
            
            if(square < n ){
                ans = mid;
                s = mid+1;
            }
            else
            {
                e = mid - 1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }

double morePrecision(int n, int precision, int tempSol) {    //FUNCTION FOR THE FLOATING NO.OF SQUARE ROOT
    
    double factor = 1;
    double ans = tempSol;

    for(int i=0; i<precision; i++) {
        factor = factor/10;

        for(double j=ans; j*j<n; j= j+factor ){
            ans = j;
        }
    }
    return ans;
}

int main() {
    int n;
    cout <<" Enter the number " << endl;
    cin >> n;

    int tempSol = sqrtInteger(n);   //CALLING OF FUNCTION
    cout <<" Answer is " << morePrecision(n, 3, tempSol) << endl;     //CALLING AD PRINTING OF FUNCTION AND ANSWER RESPECTIVELY

    return 0;
}
