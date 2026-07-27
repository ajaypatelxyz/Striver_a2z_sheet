class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxValue = INT_MIN;
        int ans;

        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                ans = (nums[i]-1) * (nums[j]-1);
                maxValue = max(maxValue, ans);
            }
        }
        return maxValue;
    }
};