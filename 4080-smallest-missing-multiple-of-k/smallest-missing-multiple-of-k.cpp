class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) 
    {
        unordered_set<int>st;
        for(int i=0; i<nums.size(); i++)
        {
            st.insert(nums[i]);
        }
        int ans=k;
        while(st.find(ans) != st.end())
        {
            ans +=k;
        }
        return ans;
        
    }
};