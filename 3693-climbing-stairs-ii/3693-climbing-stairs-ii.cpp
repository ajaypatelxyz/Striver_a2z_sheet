class Solution {
public:
    // int solve(int n, vector<int> &costs, int i, int j, vector<vector<int>> &dp){
    //     if(j > costs.size()){
    //         return INT_MAX;
    //     }

    //     int cost = costs[j - 1] + ((j - i) * (j - i));

    //     if(j == n){
    //         return cost;
    //     }

    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }
        
    //     int oneStep = solve(n, costs, j, j + 1, dp);
    //     int twoStep = solve(n, costs, j, j + 2, dp);
    //     int threeStep = solve(n, costs, j, j + 3, dp);

    //     int mini = min(oneStep, min(twoStep, threeStep));
    //     if(mini == INT_MAX){
    //         dp[i][j] = INT_MAX;
    //         return dp[i][j];
    //     }
    //     dp[i][j] = mini + cost;
    //     return dp[i][j];
    // }

    int climbStairs(int n, vector<int>& costs) {
        
        //it give MLE

        // vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        // int one = solve(n, costs, 0, 1, dp);
        // int two = solve(n, costs, 0, 2, dp);
        // int three = solve(n, costs, 0, 3, dp);
        // return min(one, min(two, three));

        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for(int j = 1; j <= n; j++){
            for(int jump = 1; jump <= 3; jump++){
                int i = j - jump;

                if(i >= 0 && dp[i] != INT_MAX){
                    int cost = costs[j - 1] + jump * jump;
                    dp[j] = min(dp[j], dp[i] + cost);
                }
            }
        }
        return dp[n];
    }
};