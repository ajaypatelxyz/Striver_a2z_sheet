class Solution {
public:
    // int solveGetMoney(int s, int e, vector<vector<int>> &dp){
    //     if(s >= e){
    //         return 0;
    //     }
    //     //Check answer already in dp or not
    //     if(dp[s][e] != -1){
    //         return dp[s][e];
    //     }

    //     int ans = INT_MAX;
    //     for(int i = s; i <= e; i++){
    //         ans = min(ans, i + max(solveGetMoney(s, i-1, dp), solveGetMoney(i+1, e, dp)));
    //     }
    //     dp[s][e] = ans;
    //     return dp[s][e];
    // }

    int solveGetMoney(int n){
        vector<vector<int>> dp(n+2, vector<int> (n+1, 0));

        for(int start = n; start >= 1; start--){
            for(int end = 1; end <= n; end++){

                if(start >= end){
                    continue;
                }
                int ans = INT_MAX;
                for(int i = start; i <= end; i++){
                    ans = min(ans, i + max(dp[start][i-1], dp[i+1][end]));
                }
                dp[start][end] = ans;
            }
        }
        return dp[1][n];
    }

    int getMoneyAmount(int n) {
        int start = 1;
        int end = n;
        
        int ans = solveGetMoney(n);
        return ans;
    }
};