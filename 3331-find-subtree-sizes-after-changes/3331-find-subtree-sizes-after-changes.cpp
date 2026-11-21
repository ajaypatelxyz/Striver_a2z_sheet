class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj, string &s, vector<int>& last, vector<int> &newParent){
        int c = s[u] - 'a';

        int old = last[c];
        if(u != 0 && old != -1){
            newParent[u] = old;
        }

        last[c] = u;
        for(int v: adj[u]){
            dfs(v, adj, s, last, newParent);
        }
        last[c] = old;
    }

    int dfs2(int u, vector<vector<int>> &adj, vector<int> &answer){
        int size = 1;

        for(int v: adj[u]){
            size += dfs2(v, adj, answer);
        }

        answer[u] = size;
        return size;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n);
        for(int i = 1; i < n; i++){
            adj[parent[i]].push_back(i);
        }

        vector<int> newParent = parent;
        vector<int> last(26, -1);

        dfs(0, adj, s, last, newParent);

        vector<vector<int>> newAdj(n);
        for(int i = 1; i < n; i++){
            newAdj[newParent[i]].push_back(i);
        }

        vector<int> answer(n, 0);
        dfs2(0, newAdj, answer);
        return answer;
    }
};