class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int n = nums.size();
        int cnt = 0;

        for (int l = 0, r = 0; r < n; r++) {
            const int x = nums[r];

            auto it = freq.find(x);
            int& f = (it == freq.end()) ? freq[x] = 1 : ++(it->second);

            while (f > k)
                freq[nums[l++]]--;

            cnt = max(cnt, r - l + 1);
        }

        return cnt;
    }
};