class Solution {
public:
    int solveNiceSubarray(vector<int> nums, int k){
        int res = 0, left = 0;

        for(int right = 0; right < nums.size(); right++){
            if(nums[right] % 2 != 0){
                k--;
            }
            while(k < 0){
                if(nums[left] % 2 != 0){
                    k++;
                }
                left++;
            }
            res += (right - left + 1);
        }
        return res;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solveNiceSubarray(nums, k) - solveNiceSubarray(nums, k-1);
    }
};