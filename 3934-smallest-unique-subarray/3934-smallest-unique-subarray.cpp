class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        const long long MOD1 = 1e9+7;
        const long long MOD2 = 1e9+9;
        const long long BASE = 911382323;

        vector<long long>h1(n + 1, 0), h2(n + 1, 0);
        vector<long long>p1(n + 1, 1), p2(n + 1, 1);

        for(int i = 0; i < n; i++){
            h1[i + 1] = (h1[i] * BASE + nums[i]) % MOD1;
            h2[i + 1] = (h2[i] * BASE + nums[i]) % MOD2;

            p1[i + 1] = (p1[i] * BASE) % MOD1;
            p2[i + 1] = (p2[i] * BASE) % MOD2;
        }

        auto check = [&](int len) -> bool{
            unordered_map<long long, int> freq;

            for(int i = 0; i + len <= n; i++){
                int j = i + len;

                long long a = (h1[j] - h1[i] * p1[len] % MOD1 + MOD1) % MOD1;
                long long b = (h2[j] - h2[i] * p2[len] % MOD2 + MOD2) % MOD2;
                long long hashValue = a * MOD2 + b;
                freq[hashValue]++;
            }

            for(auto& it: freq){
                if(it.second == 1){
                    return true;
                }
            }
            return false;
        };

        int low = 1, high = n;
        int ans = n;
        while(low <= high){
            int mid = low + (high - low) / 2;

            if(check(mid)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};