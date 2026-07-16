class Solution {
public:
    long long gcd(long long a, long long b) 
    {
        
        while (b) {
            long long temp = a%b;
            a = b;
            b = temp;
        }

        return a;
    }

    long long gcdSum(vector<int>& nums) 
    {
        int n=nums.size();

        vector<long long>prefixGcd;

        long long mx= 0;

        for(int i = 0; i < n; i++) 
        {
            mx= max(mx, (long long)nums[i]);

            prefixGcd.push_back(gcd(nums[i], mx));

        }

        sort(prefixGcd.begin(), prefixGcd.end());

        long long ans= 0;
        int left = 0, right = n - 1;


        while(left< right) {
            ans += gcd(prefixGcd[left], prefixGcd[right]);
            left++;

            right--;

        }

        return ans;
        
    }
};