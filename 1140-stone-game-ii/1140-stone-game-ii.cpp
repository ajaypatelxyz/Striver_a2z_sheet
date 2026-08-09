class Solution {
public:
    int solveStone(vector<int> piles, int index, int n, bool alice, int M, vector<vector<vector<int>>> &dp){
        if(index >= n){
            return 0;
        }
        //check answer already exists or not
        if(dp[index][M][alice] != -1){
            return dp[index][M][alice];
        }

        int ans = alice ? INT_MIN : INT_MAX;
        int sum = 0;
        for(int X = 1; X <= 2*M; X++){
            if(index + X > n) break;

            sum += piles[index + X - 1];
            int newM = max(M, X);
            if(alice){
                ans = max(ans, sum + solveStone(piles, index + X, n, false, newM, dp));
            }else{
                ans = min(ans, solveStone(piles, index + X, n, true, newM, dp));
            }
        }
        dp[index][M][alice] = ans;
        return dp[index][M][alice];
    }

    int stoneGameII(vector<int>& piles) {
        int index = 0;
        int n = piles.size();
        bool alice = true;
        int M = 1;
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (n + 1, vector<int> (2, -1)));
        int ans = solveStone(piles, index, n, alice, M, dp);
        return ans;
    }
};