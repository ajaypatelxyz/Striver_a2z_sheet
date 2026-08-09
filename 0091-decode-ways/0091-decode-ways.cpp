class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();

        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        if(s[0] != '0'){
            dp[1] = 1;
        }

        for(int i = 2; i <= n; i++){
            if(s[i - 1] != '0'){
                dp[i] += dp[i - 1];
            }

            int number = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if(number >= 10 && number <= 26){
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};