class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=1;
        int n=nums.size();
        int el=nums[0];
        for(int i=1;i<n;i++)
        {
            if(cnt==0)
            {
                el=nums[i];
            }
            if(el==nums[i])
                cnt++;
            else
                cnt--;
        }
        return el;
        
    }
};