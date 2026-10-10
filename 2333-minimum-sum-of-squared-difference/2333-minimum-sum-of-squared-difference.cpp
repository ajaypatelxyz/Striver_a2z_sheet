class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = (long long)k1 + k2;
        int n = nums1.size();

        vector<int> diff(n);
        int maxi = 0;
        for(int i = 0; i < n; i++){
            diff[i] = abs(nums1[i] - nums2[i]);
            maxi = max(maxi, diff[i]);
        }

        long long total = 0;
        for(int d: diff){
            total += d;
        }
        if(total <= k) return 0;

        int low = 0, high = maxi;
        while(low < high){
            int mid = low + (high - low)/2;
            long long operation = 0;
            for(int d: diff){
                if(d > mid){
                    operation += d - mid;
                }
            }
            if(operation <= k){
                high = mid;
            }else{
                low = mid + 1;
            }
        }

        long long ans = 0;
        long long operation = k;
        vector<int> finalDiff;

        for(int d: diff){
            if(d > low){
                operation -= d - low;
                d = low;
            }
            finalDiff.push_back(d);
        }

        sort(finalDiff.rbegin(), finalDiff.rend());

        for(int i = 0; i < n; i++){
            if(operation > 0 && finalDiff[i] > 0){
                finalDiff[i]--;
                operation--;
            }
            ans += 1LL * finalDiff[i] * finalDiff[i];
        }
        return ans;
    }
};