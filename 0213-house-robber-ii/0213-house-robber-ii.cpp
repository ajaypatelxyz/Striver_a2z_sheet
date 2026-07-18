class Solution {
public:
    int solveRob(vector<int> nums, int start, int end, vector<int> &dp){
        if(start >= end){
            return 0;
        }

        if(dp[start] != -1){
            return dp[start];
        }
        int ans1 = nums[start] + solveRob(nums, start + 2, end, dp);
        int ans2 = 0 + solveRob(nums, start + 1, end, dp);
        dp[start] = max(ans1, ans2);
        return dp[start];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        int index = 0;

        int ans1 = solveRob(nums, index+1, n, dp1);
        int ans2 = solveRob(nums, index, n-1, dp2);

        int finalAns = max(ans1, ans2);
        return finalAns;
    }
};