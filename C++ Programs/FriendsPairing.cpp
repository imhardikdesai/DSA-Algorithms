/*
Given n friends, each one can remain single or can be paired up with 
some other friend. Each friend can be paired only once. Find out the 
total number of ways in which friends can remain single or can be paired up. 
*/

#include <bits/stdc++.h>
using namespace std;

void preComputeFact(vector<long long int>& fact, int n)
{
	for(int i = 1; i <= n; i++) fact.push_back(fact[i - 1] * i);
}

int countFriendsPairings(vector<long long int> fact, int n)
{
	int ones = n, twos = 1, ans = 0;
	
	while (ones >= 0)
	{
		
		ans += fact[n] / (twos * fact[ones] * fact[(n - ones) / 2]);
		ones -= 2;
		twos *= 2;
	}
	return ans;
}

int main()
{
	vector<long long int> fact;
	fact.push_back(1);

	preComputeFact(fact, 100);
	int n = 4;

	cout << countFriendsPairings(fact, n) << endl;
	return 0;
}
