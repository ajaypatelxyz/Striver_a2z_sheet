class Solution {
public:
    int solveMinDistance(string a, string b, int i, int j, vector<vector<int>> &dp){
        if(i == a.length()){
            return b.length() - j;
        }
        if(j == b.length()){
            return a.length() - i;
        }

        //check answer is already exist or not
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ans = 0;
        if(a[i] == b[j]){
            ans = 0 + solveMinDistance(a, b, i+1, j+1, dp);
        }else{
            int replace = 1 + solveMinDistance(a, b, i+1, j+1, dp);
            int insert = 1 + solveMinDistance(a, b, i, j+1, dp);
            int remove = 1 + solveMinDistance(a, b, i+1, j, dp);
            ans = min(replace, min(insert, remove));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }

    int minDistance(string word1, string word2) {
        int i = 0;
        int j = 0;
        vector<vector<int>> dp(word1.size()+1, vector<int> (word2.size()+1, -1));
        int ans = solveMinDistance(word1, word2, i, j, dp);
        return ans;
    }
};