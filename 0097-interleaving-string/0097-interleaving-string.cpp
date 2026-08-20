class Solution {
public:
    bool solveLeave(string &s1, string &s2, string &s3, int i, int j, string &ans, vector<vector<int>> &dp){
        if(i == s1.length() && j == s2.length()){
            return true;
        }
        //check ans already exits or not
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int k = i + j;
        bool ans1 = false;
        bool ans2 = false;
        // take from s1
        if(i < s1.length() && s1[i] == s3[k]){
            ans += s1[i];
            ans1 = solveLeave(s1, s2, s3, i + 1, j, ans, dp);
            // backtracking
            ans.pop_back();
        }
        //take from s2
        if(j < s2.length() && s2[j] == s3[k]){
            ans += s2[j];
            ans2 = solveLeave(s1, s2, s3, i, j + 1, ans, dp);
            // backtracking
            ans.pop_back();
        }
        dp[i][j] = ans1 || ans2;
        return dp[i][j];
    }

    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length()) return false;
        int i = 0;
        int j = 0;
        int n = s1.length();
        int m = s2.length();
        string ans = "";
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        return solveLeave(s1, s2, s3, i, j, ans, dp);
    }
};