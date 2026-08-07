class Solution {
public:
    bool isValidRight(vector<vector<int>> nums, int i, int j, int n, int m){
        if(i < n && j < m && nums[i][j] != 1){
            return true;
        }
        return false;
    }

    bool isValidDown(vector<vector<int>> nums, int i, int j, int n, int m){
        if(i < n && j < m && nums[i][j] != 1){
            return true;
        }
        return false;
    }

    int solvePath(vector<vector<int>> obstacleGrid, int i, int j, int n, int m, vector<vector<int>> &dp){
        if(i == n - 1 && j == m - 1){
            return 1;
        }
        if(i >= n || j >= m){
            return 0;
        }
        //check answer already exists or not
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int rightAns = 0;
        //check right side
        if(isValidRight(obstacleGrid, i, j + 1, n, m)){
            rightAns = solvePath(obstacleGrid, i, j + 1, n, m, dp);
        }
        int downAns = 0;
        //check down side
        if(isValidDown(obstacleGrid, i + 1, j, n, m)){
            downAns = solvePath(obstacleGrid, i + 1, j, n, m, dp);
        }

        dp[i][j] = rightAns + downAns;
        return dp[i][j];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int i = 0;
        int j = 0;
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<vector<int>> dp(n, vector<int> (m, -1));
        if((i == n - 1 && j == m - 1 && obstacleGrid[i][j] == 1) || (obstacleGrid[i][j] == 1)){
            return 0;
        }
        int ans = solvePath(obstacleGrid, i, j, n, m, dp);
        return ans;
    }
};