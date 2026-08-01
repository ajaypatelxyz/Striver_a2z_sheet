class Solution {
public:
    int solve(vector<int>& nums, int left, int right, vector<vector<int>> &dp){
        if(left > right){
            return 0;
        }
        //check answer is already present or not
        if(dp[left][right] != -1){
            return dp[left][right];
        } 

        int playLeft = nums[left] - solve(nums, left+1, right, dp);
        int playRight = nums[right] - solve(nums, left, right-1, dp);

        dp[left][right] = max(playLeft, playRight);
        return dp[left][right];
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        int diff = solve(nums, 0, n-1, dp);
        if(diff >= 0){
            return true;
        }
        return false;
    }
};