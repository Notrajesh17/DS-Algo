class Solution {
private:
    int n, m;
    vector<vector<vector<int>>> dp;
    int dfs(int i, int j, int temp, vector<vector<int>>& nums){
        if(i >= n || j >= m){
            return INT_MAX;
        }
        temp ^= nums[i][j];
        if(i == n-1 && j == m-1){
            return temp;
        }
        if(dp[i][j][temp] != -1){
            return dp[i][j][temp];
        }
        int right = dfs(i+1, j, temp, nums);
        int down = dfs(i, j+1, temp, nums);
        return dp[i][j][temp] = min(right, down);
    }
public:
    int minCost(vector<vector<int>>& nums) {
        n = nums.size();
        m = nums[0].size();
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(1024, -1)));
        return dfs(0, 0, 0, nums);
    }
};