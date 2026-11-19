class Solution {
public:
    bool check(vector<int>& curr, vector<int>& prev){
        if(curr[0] >= prev[0] && curr[1] >= prev[1] && curr[2] >= prev[2]){
            return true;
        }else{
            return false;
        }
    }

    int solveUsingTab(vector<vector<int>>& nums){
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));

        for(int curr = n - 1; curr >= 0; curr--){
            for(int prev = curr - 1; prev >= -1; prev--){
                int include = 0;
                if(prev == -1 || check(nums[curr], nums[prev])){
                    int height = nums[curr][2];
                    include = height + dp[curr + 1][curr + 1];
                }
                int exclude = 0 + dp[curr + 1][prev + 1];
                dp[curr][prev + 1] = max(include, exclude);
            }
        }
        return dp[0][0];
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &cuboid: cuboids){
            sort(cuboid.begin(), cuboid.end());
        }
        sort(cuboids.begin(), cuboids.end());
        int ans = solveUsingTab(cuboids);
        return ans;
    }
};