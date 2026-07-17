class Solution {
public:
    int solveRob(vector<int> nums, vector<int>& db, int idx){
        if(idx >= nums.size()){
            return 0;
        }

        if(db[idx] != -1){
            return db[idx];
        }

        int ans1 = nums[idx] + solveRob(nums, db, idx+2);
        int ans2 = 0 + solveRob(nums, db, idx+1);
        db[idx] = max(ans1, ans2);
        return db[idx];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        int idx = 0;
        vector<int>db(n, -1);
        int ans = solveRob(nums, db, idx);
        return ans;
    }
};