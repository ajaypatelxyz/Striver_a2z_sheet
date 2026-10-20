class Solution {
    bool isRotation(vector<int>& nums, vector<int>& sorted, int start, int k) {
        vector<int> pattern(sorted.begin() + start, sorted.begin() + start + k);

        vector<int> lps(k, 0);

        for (int i = 1, len = 0; i < k;) {
            if (pattern[i] == pattern[len]) {
                lps[i++] = ++len;
            } else if (len > 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }

        int j = 0;

        for (int i = 0; i < 2 * k - 1; i++) {
            int value = nums[start + (i % k)];

            while (j > 0 && value != pattern[j])
                j = lps[j - 1];

            if (value == pattern[j])
                j++;

            if (j == k)
                return true;
        }
        return false;
    }

public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        long long ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0)
                continue;

            bool possible = true;

            for (int start = 0; start < n; start += k) {
                if (!isRotation(nums, sorted, start, k)) {
                    possible = false;
                    break;
                }
            }

            if (possible)
                ans += k;
        }
        return static_cast<int>(ans);
    }
};