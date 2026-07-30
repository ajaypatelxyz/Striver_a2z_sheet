class Solution {
public:
    bool solvePartition(vector<int> &nums, int index, int currSum, int target, vector<vector<int>> &dp){
        //base case
        if(currSum == target){
            return true;
        }
        if(index >= nums.size()){
            return false;
        }
        if(currSum > target){
            return false;
        }
        if(dp[index][currSum] != -1){
            return dp[index][currSum];
        }

        bool include = solvePartition(nums, index+1, currSum + nums[index], target, dp);
        bool exclude = solvePartition(nums, index+1, currSum, target, dp);
        dp[index][currSum] = (include || exclude);
        return dp[index][currSum];
    }

    bool canPartition(vector<int>& nums) {
        
        int totalSum = 0;
        for(int x: nums){
            totalSum += x;
        }
        if(totalSum % 2 == 1){
            return false;
        }
        int target = totalSum / 2;
        int n = nums.size();
        int index = 0;
        int currentSum = 0;
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        bool ans = solvePartition(nums, index, currentSum, target, dp);
        return ans;
    }
};