class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j, int n, int m, int result, vector<vector<vector<int>>> &dp){
        if(i >= n || j >= m){
            return INT_MAX;
        }

        result = result ^ grid[i][j];
        if(dp[i][j][result] != -1){
            return dp[i][j][result];
        }

        if(i == n - 1 && j == m - 1){
            return result;
        }

        int rightAns = solve(grid, i, j + 1, n, m, result, dp);
        int downAns = solve(grid, i + 1, j, n, m, result, dp);

        dp[i][j][result] = min(rightAns, downAns);
        return dp[i][j][result];
    }

    int minCost(vector<vector<int>>& grid) {
        int i = 0;
        int j = 0;
        int result = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (1024, -1)));
        int ans = solve(grid, i, j, n, m, result, dp);
        return ans;
    }
};