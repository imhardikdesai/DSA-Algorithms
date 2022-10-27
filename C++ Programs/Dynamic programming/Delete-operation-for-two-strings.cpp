/* Problem statement
Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.
*/

/* 
input/output
Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
*/


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lcsVariation(string &word1,string &word2,int n,int m, vector<vector<int>>&dp){
        if(n==0 && m==0) return 0;
        if(n==0 || m==0)  return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        if(word1[n-1]==word2[m-1]){
            dp[n][m]=1+lcsVariation(word1,word2,n-1,m-1,dp);
            return dp[n][m];
        }
        else{
          return dp[n][m]= max(lcsVariation(word1,word2,n-1,m,dp),lcsVariation(word1,word2,n,m-1,dp));
        
        }
       
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
          int answer2=lcsVariation(word1,word2,n,m,dp);
          int answer=(n+m-2*answer2);
        
        return answer;
          
    }
};