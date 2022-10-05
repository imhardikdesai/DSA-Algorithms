#include <bits/stdc++.h>
using namespace std;
int dp[1001][10000];
int countSubsets(vector<int>& v, int i, int S2,
				int currentSum)
{
	if (currentSum == S2) {
		return 1;
	}
	if (i >= v.size()) {
		return 0;
	}
	if (dp[i][currentSum] != -1) {
		return dp[i][currentSum];
	}
	if (currentSum + v[i] > S2) {
		return dp[i][currentSum]
			= countSubsets(v, i + 1, S2, currentSum);
	}
	else {
		return dp[i][currentSum]
			= countSubsets(v, i + 1, S2,
							currentSum + v[i])
				+ countSubsets(v, i + 1, S2, currentSum);
	}
}
int countSub(vector<int>& vp, int N, int diff)
{
	int sum = 0; // Calculating total sum
	for (auto& value : vp)
		sum += value;
	if (sum - diff < 0 || (sum - diff) % 2 == 1) {
		return 0;
	}
	return countSubsets(vp, 0, (sum - diff) / 2, 0);
}
int main()
{
	int N = 5;
	vector<int> arr = { 1, 2, 3, 1, 2 };
	int diff = 1;
	memset(dp, -1, sizeof(dp));
	cout << countSub(arr, N, diff) << endl;
	return 0;
}
