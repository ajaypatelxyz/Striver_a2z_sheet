class Solution {
public:
    void dfs(int value, vector<bool> &suspecious, vector<vector<int>> &adj){
        suspecious[value] = true;

        for(int next: adj[value]){
            if(!suspecious[next]){
                dfs(next, suspecious, adj);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);

        for(auto &edge: invocations){
            adj[edge[0]].push_back(edge[1]);
        }

        vector<bool> suspecious(n, false);
        dfs(k, suspecious, adj);

        for(auto &edge: invocations){
            int u = edge[0];
            int v = edge[1];

            if(!suspecious[u] && suspecious[v]){
                vector<int> ans;
                for(int i = 0; i < n; i++){
                    ans.push_back(i);
                }
                return ans;
            }
        }
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(!suspecious[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};