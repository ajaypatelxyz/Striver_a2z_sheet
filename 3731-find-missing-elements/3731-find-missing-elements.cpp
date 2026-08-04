class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int start = nums[0];
        int end = nums[nums.size() - 1];

        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            int val = nums[i];
            mp[val] = i;
        }

        vector<int> ans;
        while(start < end){
            int val = start;
            if(mp.find(val) == mp.end()){
                ans.push_back(start);
            }
            start++;
        }
        return ans;
    }
};