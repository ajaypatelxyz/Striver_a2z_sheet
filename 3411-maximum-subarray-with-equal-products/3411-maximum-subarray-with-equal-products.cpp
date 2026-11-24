class Solution {
public:
    vector<int> getPrimeFactors(int x){
        vector<int> factors;

        for(int p = 2; p <= x/p; p++){
            if(x % p == 0){
                factors.push_back(p);
                while(x % p == 0){
                    x = x/p;
                }
            }
        }
        if(x > 1){
            factors.push_back(x);
        }
        return factors;
    }

    int maxLength(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 0) return 0;
        vector<vector<int>> factors(n);

        for (int i = 0; i < n; i++) {
            factors[i] = getPrimeFactors(nums[i]);
        }

        // Any subarray of length 1 or 2 is valid.
        int ans = min(n, 2);

        unordered_map<int, int> freq;
        int left = 0;

        for (int right = 0; right < n; right++) {
            // Shrink the window while a common prime exists.
            while (true) {
                bool conflict = false;

                for (int p : factors[right]) {
                    if (freq[p] > 0) {
                        conflict = true;
                        break;
                    }
                }

                if (!conflict) break;

                // Remove the left element from the window.
                for (int p : factors[left]) {
                    freq[p]--;
                }

                left++;
            }

            // Add the current element.
            for (int p : factors[right]) {
                freq[p]++;
            }

            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};