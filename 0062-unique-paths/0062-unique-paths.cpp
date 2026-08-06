class Solution {
public:
    int solvePath(int m, int n, int i, int j, vector<vector<int>> &dp){
        if(i == m-1 && j == n-1){
            return 1;
        }
        if(i >= m || j >= n){
            return 0;
        }
        //check answer is present ot not
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int rightAns = solvePath(m, n, i, j + 1, dp);
        int downAns = solvePath(m, n, i + 1, j, dp);
        dp[i][j] = rightAns + downAns;

        return dp[i][j];
    }
    int uniquePaths(int m, int n) {
        int i = 0;
        int j = 0;
        vector<vector<int>> dp(m, vector<int> (n, -1));
        int ans = solvePath(m, n, i, j, dp);
        return ans;
    }
};