class Solution {
public:
    int solveGetMoney(int s, int e, vector<vector<int>> &dp){
        if(s >= e){
            return 0;
        }
        //Check answer already in dp or not
        if(dp[s][e] != -1){
            return dp[s][e];
        }

        int ans = INT_MAX;
        for(int i = s; i <= e; i++){
            ans = min(ans, i + max(solveGetMoney(s, i-1, dp), solveGetMoney(i+1, e, dp)));
        }
        dp[s][e] = ans;
        return dp[s][e];
    }

    int getMoneyAmount(int n) {
        int start = 1;
        int end = n;
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        int ans = solveGetMoney(start, end, dp);
        return ans;
    }
};