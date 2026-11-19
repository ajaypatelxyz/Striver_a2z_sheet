class Solution {
public:
    int solveUsingRecursion(vector<int>& nums, int curr, int prev){
        if(curr >= nums.size()){
            return 0;
        }

        int include = 0;
        if(prev == -1 || nums[curr] > nums[prev]){
            include = 1 + solveUsingRecursion(nums, curr + 1, curr);
        }
        int exclude = 0 + solveUsingRecursion(nums, curr + 1, prev);
        int ans = max(include, exclude);
        return ans;
    }

    int solveUsingMem(vector<int>& nums, int curr, int prev, vector<vector<int>> &dp){
        if(curr >= nums.size()){
            return 0;
        }
        //answer already exists
        if(dp[curr][prev + 1] != -1){
            return dp[curr][prev + 1];
        }

        int include = 0;
        if(prev == -1 || nums[curr] > nums[prev]){
            include = 1 + solveUsingMem(nums, curr + 1, curr, dp);
        }
        int exclude = 0 + solveUsingMem(nums, curr + 1, prev, dp);
        dp[curr][prev + 1] = max(include, exclude);
        return dp[curr][prev + 1];
    }

    int solveUsingTab(vector<int>& nums){
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));

        for(int curr = n - 1; curr >= 0; curr--){
            for(int prev = curr - 1; prev >= -1; prev--){
                int include = 0;
                if(prev == -1 || nums[curr] > nums[prev]){
                    include = 1 + dp[curr + 1][curr + 1];
                }
                int exclude = 0 + dp[curr + 1][prev + 1];
                dp[curr][prev + 1] = max(include, exclude);
            }
        }
        return dp[0][0];
    }

    int solveUsingSO(vector<int>& nums){
        int n = nums.size();
        // vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
        vector<int> currRow(n + 1, 0);
        vector<int> nextRow(n + 1, 0);

        for(int curr = n - 1; curr >= 0; curr--){
            for(int prev = curr - 1; prev >= -1; prev--){
                int include = 0;
                if(prev == -1 || nums[curr] > nums[prev]){
                    include = 1 + nextRow[curr + 1];
                }
                int exclude = 0 + nextRow[prev + 1];
                currRow[prev + 1] = max(include, exclude);
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int curr = 0;
        int prev = -1;
        // vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        int ans = solveUsingSO(nums);
        return ans;
    }
};