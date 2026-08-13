class Solution {
private:
    void Merge(vector<int>& nums, int low, int mid, int high)
    {
        int left = low;
        int right = mid+1;

        vector<int>temp;

        while(left<=mid && right<=high)
        {
            if(nums[left]<=nums[right])
            {
                temp.push_back(nums[left]);
                left++;
            }
            else
            {
                temp.push_back(nums[right]);
                right++;
            }

        }
        while(left<=mid )
        {
            temp.push_back(nums[left]);
            left++;
            
        }
        while(right<=high)
        {
            
            temp.push_back(nums[right]);
            right++;
        }

        for(int i=low; i<=high; i++)
        {
            nums[i]= temp[i-low];
        }

    }
    void MergeHelper(vector<int>& nums, int low, int high)
    {
        if(low>=high) return;
        int mid = (low+high)/2;
        MergeHelper(nums, low, mid);
        MergeHelper(nums, mid+1, high);
        Merge(nums, low, mid, high);
    }
public:
    vector<int> sortArray(vector<int>& nums) 
    {
        int n = nums.size();
        MergeHelper(nums, 0, n-1);
        return nums;
        
    }
};