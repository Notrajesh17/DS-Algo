class Solution {
private:
    int findMax(vector<int>& nums)
    {
        int maxi=INT_MIN;
        for(int i=0; i<nums.size(); i++)
        {
            maxi= max(maxi, nums[i]);
        }
        return maxi;
    }
    int SumofNums(vector<int>& nums)
    {
        int sum=0;
        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
        }
        return sum;
    }
    int studentCount(vector<int>&nums, int pages)
    {
        int n=nums.size();
        int student=1;
        int pageStudent=0;
        for(int i=0; i<n; i++)
        {
            if(pageStudent+nums[i]<=pages)
            {
                pageStudent += nums[i];
            }
            else
            {
                student++;
                pageStudent=nums[i];
            }
        }
        return student;

    }
public:
    int splitArray(vector<int>& nums, int m) 
    {
        int n = nums.size();
        if(n<m) return -1;
        int low=findMax(nums);
        int high=SumofNums(nums);
        while(low<=high)
        {
            int mid=(low+high)/2;
            int student = studentCount(nums, mid);
            if(student>m)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return low;
        
    }
};