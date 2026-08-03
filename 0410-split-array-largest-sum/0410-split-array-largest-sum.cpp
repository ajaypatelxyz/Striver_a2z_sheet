class Solution {
public:
    int countSubarray(vector<int> &nums, int maxSum){
        int sum = 0;
        int part = 1;
        for(int i = 0; i < nums.size(); i++){
            if(sum + nums[i] <= maxSum){
                sum += nums[i];
            }else{
                part++;
                sum = nums[i];
            }
        }
        return part;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = 0, high = 0;
        for(int x: nums){
            low = max(low, x);   //max value
            high += x;  //sum of all number
        }

        int ans = high;
        while(low <= high){
            int mid = low + (high-low)/2;

            int parts = countSubarray(nums, mid);
            if(parts <= k){
                ans = mid;
                high = mid-1;  //search small value
            }else{
                low = mid+1;   //search large value
            }
        }
        return ans;
    }
};