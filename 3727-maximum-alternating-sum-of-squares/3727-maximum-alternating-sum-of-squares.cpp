class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long score = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end(), [](int a, int b){
            return abs((long long)a) > abs((long long)b);
        });

        int first = (n + 1) / 2;

        for(int i = 0; i < first; i++){
            score += 1LL * nums[i] * nums[i];
        }
        for(int i = first; i < n; i++){
            score -= 1LL * nums[i] * nums[i];
        }
        return score;
    }
};