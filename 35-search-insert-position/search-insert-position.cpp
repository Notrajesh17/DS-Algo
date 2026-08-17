class Solution {
public:
    int searchInsert(vector<int>& nums, int x) 
    {
        int n = nums.size();
        int low=0;
        int high=n-1;
        int ans = nums.size();
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(nums[mid]>=x)
            {
                ans = mid;
                high=mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return ans;
    }
};