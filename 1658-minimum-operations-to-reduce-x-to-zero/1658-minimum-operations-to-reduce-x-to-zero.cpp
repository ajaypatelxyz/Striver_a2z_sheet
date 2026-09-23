class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        
        int totalSum = 0;
        for(int i = 0; i < n; i++){
            totalSum += nums[i];
        }
        int target = totalSum - x;
        if(target < 0) return -1;
        if(target == 0) return n;
        
        int i = 0;
        int j = 0;
        int sum = 0;
        int maxLen = 0;
        while(j < n){
            sum += nums[j];

            while(sum > target){
                sum -= nums[i];
                i++;
            }
            if(sum == target){
                maxLen = max(maxLen, j - i + 1);
            }
            j++;
        }
        if(maxLen == 0) return -1;
        return n - maxLen;
    }
};