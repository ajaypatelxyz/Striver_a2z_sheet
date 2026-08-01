class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool left = true;
        bool right = true;

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i-1]){
                left = false;
            }else if(nums[i] < nums[i-1]){
                right = false;
            }
        }
        return left || right;
    }
};