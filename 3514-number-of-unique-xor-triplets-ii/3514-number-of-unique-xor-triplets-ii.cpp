class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) 
    {
        const int MAXX = 2048;

        vector<char> dp0(MAXX, 0), dp1(MAXX, 0), dp2(MAXX, 0), dp3(MAXX, 0);

        dp0[0] = 1;

        for(int x : nums) 
        {
          
            for(int v = 0; v < MAXX; v++) 
            {
                if(dp2[v]) dp3[v ^ x] = 1;
            }

            for(int v = 0; v < MAXX; v++) 
            {
                if(dp1[v]) dp2[v ^ x] = 1;
            }
            for(int v = 0; v < MAXX; v++) 
            {
                if(dp0[v]) dp1[v ^ x]= 1;
            }
        }

        vector<char> ans(MAXX, 0);

       
        for(int x : nums)
        {
            ans[x] = 1;
        }

        for(int v = 0; v < MAXX; v++)
        {
            if (dp3[v]) ans[v] = 1;
        }

        int res = 0;
        for (int v = 0; v < MAXX; v++)
        {
             res += ans[v];
        }

        return res;

    }
};