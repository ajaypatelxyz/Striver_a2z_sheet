class Solution {
public:
    int solveJump(vector<int> &nums, int index, vector<int> &dp){
        if(index == nums.size()){
            return INT_MAX;
        }
        if(index == nums.size() - 1){
            return 0;
        }
        //check answer is exist or not
        if(dp[index] != -1){
            return dp[index];
        }

        int ans = INT_MAX;
        for(int jump = 1; jump <= nums[index]; jump++){
            if(index + jump < nums.size()){
                int recursionKaAns = solveJump(nums, index + jump, dp);
                if(recursionKaAns != INT_MAX){
                    ans = min(ans, 1 + recursionKaAns);
                }
            }
        }
        dp[index] = ans;
        return dp[index];
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        int index = 0;
        vector<int> dp(n+1, -1);
        int ans =  solveJump(nums, index, dp);
        return ans;
    }
};