#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
  deque<int> dq;
  vector<int> vec;
  int i = 0, j = 0;
  while (j < nums.size())
  {
    if (dq.empty())
      dq.push_back(nums[j]);
    else
    {
      while (!dq.empty() && dq.back() < nums[j])
      {
        dq.pop_back();
      }
      dq.push_back(nums[j]);
    }
    if (j - i + 1 < k)
      j++;
    else if (j - i + 1 == k)
    {
      vec.push_back(dq.front());
      if (nums[i] == dq.front())
      {
        dq.pop_front();
      }
      i++;
      j++;
    }
  }
  return vec;
}

int main()
{
  int i, j, n, k = 3, x;
  vector<int> arr{
      4, 0,
      -1,
      3,
      5,
      3,
      6,
      8};
  vector<int> ans;
  ans = maxSlidingWindow(arr, k);
  cout << "Maximum element in every " << k << " window " << endl;
  for (i = 0; i < ans.size(); i++)
    cout << ans[i] << "  ";
  return 0;
}