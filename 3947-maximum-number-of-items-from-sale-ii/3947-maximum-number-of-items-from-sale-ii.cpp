class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> freq(n + 1, 0);
        for (auto &item : items) {
            freq[item[0]]++;
        }

        vector<int> cnt(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                cnt[i] += freq[j];
            }
        }

        int minPrice = INT_MAX;
        for (auto &item : items) {
            minPrice = min(minPrice, item[1]);
        }

        if (budget < minPrice) return 0;

        vector<pair<int, int>> v;
        for (auto &item : items) {
            int factor = item[0];
            int price = item[1];

            int freeCount = cnt[factor] - 1;
            v.push_back({price, freeCount});
        }

        sort(v.begin(), v.end());

        long long remaining = budget;
        long long ans = 0;

        for (auto &[price, count] : v) {
            if (price >= 2LL * minPrice) {
                break;
            }
            long long take = min(
                (long long)count,
                remaining / price
            );
            ans += 2 * take;
            remaining -= take * price;
        }

        ans += remaining / minPrice;
        return (int)ans;
    }
};