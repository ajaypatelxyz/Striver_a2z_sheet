class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        const int MAXF = 1500;

        // Count frequency of each factor
        vector<int> freq(MAXF + 1, 0);
        for (auto& item : items) {
            freq[item[0]]++;
        }

        // Count how many factors are divisible by each factor
        vector<int> cnt(MAXF + 1, 0);
        for (int i = 1; i <= MAXF; i++) {
            for (int j = i; j <= MAXF; j += i) {
                cnt[i] += freq[j];
            }
        }

        // Group items according to their price
        vector<vector<int>> groups(budget + 1);
        for (auto& item : items) {
            int factor = item[0];
            int price = item[1];
            if (price <= budget) {
                // Purchased copy + free copies
                int weight = cnt[factor];

                groups[price].push_back(weight);
            }
        }

        const int NEG = -1e9;
        vector<int> dp(budget + 1, NEG);
        dp[0] = 0;

        int ans = 0;
        // Minimum selected item price
        for (int p = budget; p >= 1; p--) {
            vector<int> cur(budget + 1, NEG);
            // Select at least one item having price p
            for (int weight : groups[p]) {
                for (int c = budget; c >= p; c--) {
                    if (dp[c - p] != NEG) {
                        cur[c] = max(cur[c], dp[c - p] + weight);
                    }
                    dp[c] = max(dp[c], dp[c - p] + weight);
                }
            }

            // Calculate maximum total copies
            for (int c = 0; c <= budget; c++) {
                if (cur[c] != NEG) {
                    int extra = (budget - c) / p;
                    ans = max(ans, cur[c] + extra);
                }
            }
        }
        return ans;
    }
};