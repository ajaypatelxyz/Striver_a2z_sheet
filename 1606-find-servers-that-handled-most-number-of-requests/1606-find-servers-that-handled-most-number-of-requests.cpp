class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();

        vector<int> count(k, 0);
        set<int> available;
        for(int i = 0; i < k; i++){
            available.insert(i);
        }

        priority_queue<
        pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>
        >busy;

        for(int i = 0; i < n; i++){
            int time = arrival[i];
            while(!busy.empty() && busy.top().first <= time){
                int serverId = busy.top().second;
                busy.pop();

                available.insert(serverId);
            }

            if(available.empty()){
                continue;
            }

            auto it = available.lower_bound(i % k);

            if(it == available.end()){
                it = available.begin();
            }

            int serverId = *it;
            available.erase(it);

            count[serverId]++;

            long long finishTime = (long long)time + load[i];
            busy.push({finishTime, serverId});
        }

        int maxi = *max_element(count.begin(), count.end());

        vector<int> ans;
        for(int i = 0; i < k; i++){
            if(count[i] == maxi){
                ans.push_back(i);
            }
        }
        return ans;
    }
};