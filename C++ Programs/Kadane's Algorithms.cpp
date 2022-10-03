class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n=nums.size(),mx=0;
        int s=nums[0];
        for(int i=0;i<n;i++)
        {
             mx+=nums[i];
             s=max(s,mx);
            if(mx<0)
            {
                mx=0;
            }
        }
        return s;
    }
};