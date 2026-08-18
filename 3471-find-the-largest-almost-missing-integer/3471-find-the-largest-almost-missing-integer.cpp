class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for(int i = 0; i <= nums.size() - k; i++){
            unordered_set<int> seen;

            for(int j = i; j < i + k; j++){
                if(seen.find(nums[j]) == seen.end()){
                    seen.insert(nums[j]);
                    count[nums[j]]++;
                }
            }
        }
        int ans = -1;
        for(auto it: count){
            if(it.second == 1){
                ans = max(ans, it.first);
            }
        }
        return ans;
    }
};