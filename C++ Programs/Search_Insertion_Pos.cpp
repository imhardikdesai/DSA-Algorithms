class Solution {
public:

int findMy_Ans(int low , int high , vector<int> &arr , int n  , int target){

    if(low > high){
        return low;  
    }


    int mid = (low+high)/2;

    if(arr[mid] == target){
        return mid;
    }

    else if(target > arr[mid]){
        low = mid+1;
    }

    else{
        high = mid-1;
    }

    return findMy_Ans(low , high , arr , n , target);


}


    int searchInsert(vector<int>& nums, int target) {
        
    int n=nums.size();

    int low = 0;
    int high = n-1;

    int ans = findMy_Ans(low , high , nums , n , target);

    return ans;

    }
};