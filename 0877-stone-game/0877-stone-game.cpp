class Solution {
public:
    int solveStone(vector<int>& piles, int left, int right, vector<vector<int>> &dp){
        if(left >= right){
            return 0;
        }
        //check answer already exists or not
        if(dp[left][right] != -1){
            return dp[left][right];
        }

        int leftAns = piles[left] + solveStone(piles, left + 1, right, dp);
        int rightAns = piles[right] + solveStone(piles, left, right - 1, dp);

        dp[left][right] = max(leftAns, rightAns);
        return dp[left][right];
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int left = 0;
        int right = n - 1;
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        int ans = solveStone(piles, left, right, dp);
        if(ans >= 0){
            return true;
        }
        return false;
    }
};