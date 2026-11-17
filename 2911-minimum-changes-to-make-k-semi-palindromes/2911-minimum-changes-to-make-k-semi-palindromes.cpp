class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        vector<vector<int>> cost(n, vector<int> (n, INF));
        for(int i = 0; i < n; i++){
            for(int len = 2; i + len <= n; len++){
                for(int d = 1; d < len; d++){
                    if(len % d != 0){
                        continue;
                    }

                    int changes = 0;
                    for(int r = 0; r < d; r++){
                        int cnt = (len - 1 - r)/d + 1;

                        for(int t = 0; t < cnt/2; t++){
                            int left = i + r + t * d;
                            int right = i + r + (cnt - 1 - t) * d;
                            if(s[left] != s[right]){
                                changes++;
                            }
                        }
                    }
                    cost[i][i + len - 1] = min(cost[i][i + len - 1], changes);
                }
            }
        }
        vector<vector<int>> dp(n + 1, vector<int> (k + 1, INF));
        dp[0][0] = 0;

        for(int parts = 1; parts <= k; parts++){
            for(int i = 2 * parts; i <= n; i++){
                for(int p = 2 * (parts - 1); p <= i - 2; p++){
                    if(dp[p][parts - 1] == INF){
                        continue;
                    }
                    dp[i][parts] = min(dp[i][parts], dp[p][parts - 1] + cost[p][i - 1]);
                }
            }
        }
        return dp[n][k];
    }
};