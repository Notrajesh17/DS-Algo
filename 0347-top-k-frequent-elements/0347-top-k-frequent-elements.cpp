class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int,int>mpp;

        for(int i=0; i<nums.size(); i++)
        {
            mpp[nums[i]]++;
        }
        vector<int> ans;
        while(k--)
        {
            int maxFreq=0;
            int element=0;

            for(auto it : mpp)
            {
                if(it.second>maxFreq)
                {
                    maxFreq=it.second;
                    element=it.first;
                }
            }
            ans.push_back(element);
            mpp.erase(element);

        }
        return ans;
    }
};