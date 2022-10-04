// // Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

// Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

 

// Example 1:

// Input: s = "abccccdd"
// Output: 7
// Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
// #include <bits/stdc++.h>
class Solution {
public:

     int longestPalindrome(string s) {
        unordered_map<int,int> mp;
        int res = 0;
        for(int i = 0; i < s.length(); i++) {
            mp[s[i]]++;
            if(mp[s[i]]%2==0) {
                res += mp[s[i]];
                mp[s[i]] = 0;
            }
        }
        for(auto x: mp) {
            if(x.second==1) {
              res++;
              break;
            }  
        }
        return res;
    }
    int main(){
        return longestPalindrome;
    }
};