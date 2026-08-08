class Solution {
public:
    // int solveMinPath(vector<vector<int>> grid, int i, int j, int n, int m, vector<vector<int>> &dp){
    //     if(i == n - 1 && j == m - 1){
    //         return grid[i][j];
    //     }
    //     if(i >= n || j >= m){
    //         return INT_MAX;
    //     }
    //     //check answer already exists or not
    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }

    //     int rightAns = solveMinPath(grid, i, j + 1, n, m, dp);
    //     int downAns = solveMinPath(grid, i + 1, j, n, m, dp);

    //     dp[i][j] = grid[i][j] + min(rightAns, downAns);
    //     return dp[i][j];
    // }

    int solveMinPath(vector<vector<int>> grid){
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        dp[n-1][m-1] = grid[n-1][m-1];

        //last row
        for(int j = m-2; j >= 0; j--){
            dp[n-1][j] = grid[n-1][j] + dp[n-1][j+1];
        }

        //last column
        for(int i = n-1; i >= 0; i--){
            dp[i][m-1] = grid[i][m-1] + dp[i+1][m-1];
        }

        for(int i = n-2; i >= 0; i--){
            for(int j = m-2; j >= 0; j--){
                dp[i][j] = grid[i][j] + min(dp[i][j+1], dp[i+1][j]);
            }
        }

        return dp[0][0];
    }

    int minPathSum(vector<vector<int>>& grid) {
        
        int ans = solveMinPath(grid);
        return ans;
    }
};