class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);

        for(int i = 0; i < n; i++){
            prefix[i + 1] = prefix[i] + nums[i];
        }

        auto query = [&](int l, int r) -> long long{
            return 1LL * (r - l + 1) * nums[l] - (prefix[r + 1] - prefix[l]);
        };

        long long operations = 0;
        long long ans = 0;

        deque<pair<int, int>> dq;
        for(int i = n - 1; i >= 0; i--){
            int right = i;

            while(!dq.empty() && nums[dq.back().first] <= nums[i]){
                auto [l, r] = dq.back();
                dq.pop_back();

                operations -= query(l, r);
                right = r;
            }
            operations += query(i, right);
            dq.push_back({i, right});

            while(operations > k){
                operations -= nums[dq.front().first] - nums[dq.front().second];
                dq.front().second--;

                if(dq.front().first > dq.front().second){
                    dq.pop_front();
                }
            }
            ans += dq.front().second - i + 1;
        }
        return ans;
    }
};