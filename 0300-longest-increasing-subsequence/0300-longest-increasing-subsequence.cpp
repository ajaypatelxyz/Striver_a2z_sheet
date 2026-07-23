class Solution {
public:
    int solveLIS(vector<int> &nums){
        vector<vector<int>> dp(nums.size()+1, vector<int> (nums.size()+1, 0));
        // if(curr >= nums.size()){
        //     return 0;
        // }
        // //Check answer is already exists or not
        // if(dp[curr][prev+1] != -1){
        //     return dp[curr][prev+1];
        // }

        for(int curr = nums.size() - 1; curr >= 0; curr--){
            for(int prev = curr - 1; prev >= -1; prev--){
                int include = 0;
                if(prev == -1 || nums[curr] > nums[prev]){
                    include = 1 + dp[curr+1][curr+1];
                }
                int exclude = 0 + dp[curr+1][prev+1];
                dp[curr][prev+1] = max(include, exclude);
            }
        }
        return dp[0][0];
    }

    int lengthOfLIS(vector<int>& nums) {
        int curr = 0;
        int prev = -1;
        
        int ans = solveLIS(nums);
        return ans;
    }
};