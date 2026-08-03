class Solution {
public:
    int solve(vector<int> &stoneValue, int index, int n, vector<int> &dp){
        if(index >= n){
            return 0;
        }
        //check answer already exists or not
        if(dp[index] != -1){
            return dp[index];
        }

        int ans = INT_MIN;
        int sum = 0;

        for(int take = 1; take <= 3 && index + take - 1 < n; take++){
            sum += stoneValue[index + take - 1];
            ans = max(ans, sum - solve(stoneValue, index + take, n, dp));
        }
        dp[index] = ans;
        return dp[index];
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int index = 0;
        int n = stoneValue.size();
        vector<int> dp(n+1, -1);
        int ans = solve(stoneValue, index, n, dp);

        if(ans == 0){
            return "Tie";
        }else if(ans > 0){
            return "Alice";
        }
        return "Bob";
    }
};