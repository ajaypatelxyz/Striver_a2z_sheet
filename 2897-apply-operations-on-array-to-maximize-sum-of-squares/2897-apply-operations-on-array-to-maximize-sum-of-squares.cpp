class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1e9+7;
        vector<int> cnt(32, 0);

        for(int x: nums){
            for(int bit = 0; bit < 32; bit++){
                if(x & (1LL << bit)){
                    cnt[bit]++;
                }
            }
        }

        long long ans = 0;
        for(int i = 0; i < k; i++){
            long long num = 0;
            for(int bit = 0; bit < 32; bit++){
                if(cnt[bit] > 0){
                    num = num | (1LL << bit);
                    cnt[bit]--;
                }
            }
            ans = (ans + num * num) % MOD;
        }
        return ans;
    }
};