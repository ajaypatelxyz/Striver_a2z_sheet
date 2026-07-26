class Solution {
public:
    // int solveLeafValue(vector<int> &arr, map<pair<int, int>, int> maxi, int start, int end, vector<vector<int>> &dp){
    //     if(start >= end){
    //         return 0;
    //     }
    //     //Answer already exists
    //     if(dp[start][end] != -1){
    //         return dp[start][end];
    //     }
    //     int ans = INT_MAX;
    //     for(int i = start; i < end; i++){
    //         ans = min(ans, (maxi[{start, i}] * maxi[{i+1, end}]) + solveLeafValue(arr, maxi, start, i, dp) + solveLeafValue(arr, maxi, i+1, end, dp));
    //     }

    //     dp[start][end] = ans;
    //     return dp[start][end];
    // }

    //this approach is more optimal
    int solveLeafValueTabu(vector<int> &arr, map<pair<int, int>, int> maxi){
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        
        for(int start = n-1; start >= 0; start--){
            for(int end = 0; end < n; end++){

                if(start >= end){
                    continue;
                }
                int ans = INT_MAX;
                for(int i = start; i < end; i++){
                    ans = min(ans, (maxi[{start, i}] * maxi[{i+1, end}]) + dp[start][i] + dp[i+1][end]);
                }
                dp[start][end] = ans;
            }
        }
        return dp[0][n-1];
    }

    int mctFromLeafValues(vector<int>& arr) {

        map<pair<int, int>, int> maxi;
        for(int i = 0; i < arr.size(); i++){
            maxi[{i, i}] = arr[i];
            for(int j = i; j < arr.size(); j++){
                maxi[{i, j}] = max(arr[j], maxi[{i, j-1}]);
            }
        }

        int n = arr.size();
        int start = 0;
        int end = n-1;
        // vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        int ans = solveLeafValueTabu(arr, maxi);
        return ans;
    }
};