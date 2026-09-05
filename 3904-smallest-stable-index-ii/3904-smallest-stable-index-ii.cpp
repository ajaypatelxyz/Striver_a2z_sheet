class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suffixMin(n);

        suffixMin[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--){
            suffixMin[i] = min(suffixMin[i + 1], nums[i]);
        }

        int prefixMax = INT_MIN;
        int index = INT_MAX;
        for(int i = 0; i < n; i++){

            prefixMax = max(prefixMax, nums[i]);
            int instability = prefixMax - suffixMin[i];

            if(instability <= k && index > i){
                index = i;
            }
        }
        if(index == INT_MAX) return -1;
        return index;
    }
};