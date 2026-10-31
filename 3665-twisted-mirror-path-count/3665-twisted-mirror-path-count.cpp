class Solution {
public:
    int solve(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp, bool right, int MOD){
        if(i >= n || j >= m){
            return 0;
        }
        if(i == n - 1 && j == m - 1){
            return 1;
        }
        if(dp[i][j][right] != -1){
            return dp[i][j][right];
        }

        int path;
        if(grid[i][j] == 1 && right){
            path = solve(i + 1, j, n, m, grid, dp, false, MOD);
        }else if(grid[i][j] == 1 && !right){
            path = solve(i, j + 1, n, m, grid, dp, true, MOD);
        }else{
            int rightPath = solve(i, j + 1, n, m, grid, dp, true, MOD);
            int downPath = solve(i + 1, j, n, m, grid, dp, false, MOD);
            path = (rightPath + downPath) % MOD;
        }
        dp[i][j][right] = path;
        return dp[i][j][right];
    }

    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9+7;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (2, -1)));
        bool right = true;
        int ans = solve(0, 0, n, m, grid, dp, right, MOD);
        return ans;
    }
};