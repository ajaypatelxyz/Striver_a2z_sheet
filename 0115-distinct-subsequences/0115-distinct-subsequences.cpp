class Solution {
public:
    long long solve(string &s, string &t, int i, int j, vector<vector<long long>> &dp){
        if(j == t.length()){
            return 1;
        }
        if(i == s.length()){
            return 0;
        }
        //check answer already exists or not
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        long long ans = 0;
        if(s[i] == t[j]){
            //include current value
            ans += solve(s, t, i + 1, j + 1, dp);
            //exclude cuurent value
            ans += solve(s, t, i + 1, j, dp);
        }else{
            //not equal skip this
            ans = solve(s, t, i + 1, j, dp);
        }
        return dp[i][j] = ans;
    }

    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<long long>> dp(n + 1, vector<long long> (m + 1, -1));
        int ans = solve(s, t, 0, 0, dp);
        return ans;
    }
};