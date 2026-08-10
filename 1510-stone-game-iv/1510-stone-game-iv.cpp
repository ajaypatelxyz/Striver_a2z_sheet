class Solution {
public:
    bool solveSquare(int n, vector<bool> &dp){
        if(n == 0) return false;

        //check answer already exists
        if(dp[n] != false){
            return dp[n];
        }
        for(int i = 1; i * i <= n; i++){
            if(!solveSquare(n - i * i, dp)){
                return dp[n] = true;
            }
        }
        dp[n] = false;
        return dp[n];
    }

    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);
        return solveSquare(n, dp);
    }
};