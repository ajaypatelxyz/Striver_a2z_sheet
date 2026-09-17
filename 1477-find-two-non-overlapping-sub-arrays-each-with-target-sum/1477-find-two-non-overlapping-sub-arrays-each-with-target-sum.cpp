class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int ans = INT_MAX;

        // best[i] = minimum length of a valid subarray
        // ending before index i
        vector<int> best(n, INT_MAX);

        int left = 0;
        int sum = 0;
        int minLen = INT_MAX;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            if (sum == target) {
                int len = right - left + 1;

                // Check if a previous non-overlapping subarray exists
                if (left > 0 && best[left - 1] != INT_MAX) {
                    ans = min(ans, len + best[left - 1]);
                }

                minLen = min(minLen, len);
            }

            // Store best subarray seen so far
            if (right == 0)
                best[right] = minLen;
            else
                best[right] = min(best[right - 1], minLen);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};