class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        int left = 0;
        int ans = 0;
        for(int right = 0; right < n; right++){
            mp[nums[right]]++;

            //if current value freq increase more then k time
            //move left until it become <= k
            while(mp[nums[right]] > k){
                mp[nums[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};