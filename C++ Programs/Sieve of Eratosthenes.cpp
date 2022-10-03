#include <bits/stdc++.h>

using namespace std;
vector<int> sieveOfEratosthenes(int N)
    {
        vector<int> result;
        vector<int> dp(N+1,0);
        dp[1]=1;
        for(int i=2; i<dp.size(); i++)
        {
            if(dp[i]==0){
                result.push_back(i);
                for(int j=2; j*i<=N; j++)
                {
                    dp[j*i]=1;
                    
                }
            }
        }
        return result;
    }

int main()
{
    cout<<"please enter the number"<<endl;
    int n;
    cin>>n;
    cout<<endl;
    vector<int> result= sieveOfEratosthenes(n);
    for(auto x: result)
    {
        cout<<x<<" ";
    }

    return 0;
}
