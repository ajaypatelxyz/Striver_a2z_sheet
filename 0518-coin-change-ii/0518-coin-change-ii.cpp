class Solution {
public:
    int solveCoin(int amount, vector<int> &coins, int idx, vector<vector<int>> &dp){
        if(amount == 0){
            return 1;
        }

        if(dp[amount][idx] != -1){
            return dp[amount][idx];
        }

        int ans = 0;
        for(int i = idx; i < coins.size(); i++){
            if(amount >= coins[i]){
                ans += solveCoin(amount - coins[i], coins, i, dp);
            }
        }
        dp[amount][idx] = ans;
        return dp[amount][idx];
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(amount+1, vector<int>(n+1, -1));
        int idx = 0;
        int ans = solveCoin(amount, coins, idx, dp);
        return ans;
    }
};