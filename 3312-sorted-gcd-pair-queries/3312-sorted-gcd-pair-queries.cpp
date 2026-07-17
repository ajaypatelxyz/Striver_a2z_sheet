class Solution {
public:
    void solve(vector<long long> &gcdPairs, vector<long long> &freq, int maxi){
        for(int g = maxi; g >= 1; g--){
            long long count = 0;
            for(int multiple = g; multiple <= maxi; multiple += g){
                count += freq[multiple];
            }
            gcdPairs[g] = count * (count - 1)/2;
            for(int multiple = 2*g; multiple <= maxi; multiple += g){
                gcdPairs[g] -= gcdPairs[multiple];
            }
        }
    }

    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        vector<long long> gcdPairs(maxi+1, 0);
        vector<long long> freq(maxi+1, 0);

        for(int x: nums){
            freq[x]++;
        }

        solve(gcdPairs, freq, maxi);

        vector<long long> prefix(maxi+1, 0);
        for(int i = 1; i <= maxi; i++){
            prefix[i] = prefix[i-1] + gcdPairs[i];
        }

        vector<int> ans;
        for(long long q: queries){
            int gcdValue = lower_bound(prefix.begin()+1, prefix.end(), q+1) - prefix.begin();
            ans.push_back(gcdValue);
        }
        return ans;
    }
};