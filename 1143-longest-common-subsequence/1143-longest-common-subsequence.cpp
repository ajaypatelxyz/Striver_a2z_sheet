class Solution {
public:
    int solveSubsequence(string a, string b){
        vector<vector<int>> dp(a.length() + 1, vector<int> (b.length() + 1, 0));
    
        for(int i = a.length() - 1; i >= 0; i--){
            for(int j = b.length() - 1; j >= 0; j--){
                int ans = 0;
                if(a[i] == b[j]){
                    ans = 1 + dp[i+1][j+1];
                }else{
                    ans = 0 + max(dp[i][j+1], dp[i+1][j]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int i = 0;
        int j = 0;
        
        int ans = solveSubsequence(text1, text2);
        return ans;
    }
};