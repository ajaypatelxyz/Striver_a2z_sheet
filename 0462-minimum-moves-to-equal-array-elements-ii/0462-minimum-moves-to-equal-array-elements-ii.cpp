class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int median = nums[n/2];
        int move = 0;
        for(int i = 0; i < n; i++){
            move += abs(nums[i] - median);
        }
        return move;
    }
};