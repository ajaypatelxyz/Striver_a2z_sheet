class Solution {
    const long long MOD = 1e9+7;
    vector<vector<long long>> dp;

    long long solve(vector<int> &nums){
        int n = nums.size();
        if(n <= 2) return 1;

        vector<int> left, right;
        for(int i = 1; i < n; i++){
            if(nums[i] < nums[0]){
                left.push_back(nums[i]);
            }else{
                right.push_back(nums[i]);
            }
        }

        long long way = dp[n - 1][left.size()];
        way = way * solve(left) % MOD;
        way = way * solve(right) % MOD;

        return way;
    }
public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        dp.assign(n + 1, vector<long long>(n + 1, 1));

        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= i; j++){
                if(j == 0 || j == i){
                    dp[i][j] = 1;
                }else{
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
                }
            }
        }
        return (solve(nums) - 1 + MOD) % MOD;
    }
};