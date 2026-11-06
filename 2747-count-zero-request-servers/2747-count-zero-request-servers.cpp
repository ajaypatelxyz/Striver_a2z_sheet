class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = queries.size();

        sort(logs.begin(), logs.end(), [](auto &a, auto&b){
            return a[1] < b[1];
        });

        vector<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());
        vector<int> ans(m, 0);
        vector<int> cnt(n + 1, 0);

        int left = 0;
        int right = 0;
        int active = 0;
        for(int i = 0; i < m; i++){
            int time = q[i].first;
            int idx = q[i].second;

            int start = time - x;
            while(right < logs.size() && logs[right][1] <= time){
                int id = logs[right][0];

                if(cnt[id] == 0){
                    active++;
                }
                cnt[id]++;
                right++;
            }
            while(left < right && logs[left][1] < start){
                int id = logs[left][0];

                cnt[id]--;
                if(cnt[id] == 0){
                    active--;
                }
                left++;
            }
            ans[idx] = n - active;
        }
        return ans;
    }
};