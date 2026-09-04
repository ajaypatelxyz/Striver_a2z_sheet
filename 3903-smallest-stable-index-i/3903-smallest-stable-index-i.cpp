class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> instability;

        for(int i = 0; i < n; i++){
            int maxi = INT_MIN;
            int mini = INT_MAX;
            for(int j = 0; j <= i; j++){
                maxi = max(maxi, nums[j]);
            }
            for(int j = i; j < n; j++){
                mini = min(mini, nums[j]);
            }
            int val = maxi - mini;
            instability.push_back(val);
        }
        
        for(int i = 0; i < n; i++){
            if(instability[i] <= k){
                return i;
            }
        }
        return -1;
    }
};