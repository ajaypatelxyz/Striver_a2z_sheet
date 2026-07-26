class Solution {
public:
    int maximumProduct(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        long n = nums.size();
        long option1 = nums[0] * nums[1] * nums[n-1];
        long option2 = nums[n-1] * nums[n-2] * nums[n-3];
        return max(option1, option2);

        // sort(nums.begin(), nums.end());  //sort all
        // long n = nums.size();
        // long option1 = (long)nums[0]*nums[1]*nums[n-1];
        // long option2 = (long)nums[n-1]*nums[n-2]*nums[n-3];
        // long ans = max(option1, option2);
        // return ans; 
    }
};