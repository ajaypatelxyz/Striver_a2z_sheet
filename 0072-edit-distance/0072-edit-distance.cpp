class Solution {
public:
    //This is DP Memoization method
    // int solveMinDistance(string a, string b, int i, int j, vector<vector<int>> &dp){
    //     if(i == a.length()){
    //         return b.length() - j;
    //     }
    //     if(j == b.length()){
    //         return a.length() - i;
    //     }

    //     //check answer is already exist or not
    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }

    //     int ans = 0;
    //     if(a[i] == b[j]){
    //         ans = 0 + solveMinDistance(a, b, i+1, j+1, dp);
    //     }else{
    //         int replace = 1 + solveMinDistance(a, b, i+1, j+1, dp);
    //         int insert = 1 + solveMinDistance(a, b, i, j+1, dp);
    //         int remove = 1 + solveMinDistance(a, b, i+1, j, dp);
    //         ans = min(replace, min(insert, remove));
    //     }
    //     dp[i][j] = ans;
    //     return dp[i][j];
    // }

    //This is DP tabulation method
    int solveMinDistance(string a, string b){
        vector<vector<int>> dp(a.length()+1, vector<int> (b.length()+1, 0));

        for(int col = 0; col < b.length(); col++){
            dp[a.length()][col] = b.length() - col;
        }
        for(int row = 0; row < a.length(); row++){
            dp[row][b.length()] = a.length() - row;
        }

        for(int i = a.length()-1; i >= 0; i--){
            for(int j = b.length()-1; j >= 0; j--){
                int ans = 0;
                if(a[i] == b[j]){
                    ans = 0 + dp[i+1][j+1];
                }else{
                    int replace = 1 + dp[i+1][j+1];
                    int insert = 1 + dp[i][j+1];
                    int remove = 1 + dp[i+1][j];
                    ans = min(replace, min(insert, remove));
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    int minDistance(string word1, string word2) {
        int i = 0;
        int j = 0;
        // vector<vector<int>> dp(word1.size()+1, vector<int> (word2.size()+1, -1));
        int ans = solveMinDistance(word1, word2);
        return ans;
    }
};