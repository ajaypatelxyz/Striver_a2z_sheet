class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        int mini = *min_element(nums.begin(), nums.end());

        int ans = gcd(mini, maxi);
        return ans;
    }
};