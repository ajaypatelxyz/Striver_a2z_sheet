class Solution {
public:
    bool solve(vector<vector<char>>& grid, int i, int j, int n, int m, int balance, vector<vector<vector<int>>> &dp){
        if(i >= n) return false;
        if(j >= m) return false;

        if(grid[i][j] == '('){
            balance++;
        }else{
            balance--;
        }
        if(balance < 0) return false;

        if(i == n - 1 && j == m - 1){
            return balance == 0;
        }

        if(dp[i][j][balance] != -1){
            return dp[i][j][balance];
        }

        bool downAns = solve(grid, i + 1, j, n, m, balance, dp);
        bool rightAns = solve(grid, i, j + 1, n, m, balance, dp);

        dp[i][j][balance] = downAns || rightAns;
        return dp[i][j][balance];
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int> (n + m + 1, -1)));

        if(grid[0][0] == ')') return false;
        return solve(grid, 0, 0, n, m, 0, dp);
    }
};