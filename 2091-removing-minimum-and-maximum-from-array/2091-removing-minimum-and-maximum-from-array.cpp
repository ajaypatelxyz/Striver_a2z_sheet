class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int minIdx = 0;
        int maxIdx = 0;
        for(int i = 0; i < n; i++){
            if(mini > nums[i]){
                mini = nums[i];
                minIdx = i;
            }
            if(nums[i] > maxi){
                maxi = nums[i];
                maxIdx = i;
            }
        }
        // both from left
        int option1 = max(minIdx, maxIdx) + 1;
        // both from right
        int option2 = n - min(minIdx, maxIdx);
        // min left and max right
        int option3 = minIdx + 1 + n - maxIdx;
        // max left and min right
        int option4 = maxIdx + 1 + n - minIdx;
        
        return min({option1, option2, option3, option4});
    }
};