class Solution {
public:
    struct Fenwick {
        int n;
        vector<int> bit;

        Fenwick(int n) : n(n), bit(n + 2, 0) {}

        void update(int idx, int val) {
            for (; idx <= n; idx += idx & -idx) {
                bit[idx] ^= val;
            }
        }

        int query(int idx) {
            int res = 0;
            for (; idx > 0; idx -= idx & -idx) {
                res ^= bit[idx];
            }
            return res;
        }

        // XOR update on a 0-based inclusive range
        void rangeUpdate(int l, int r, int val) {
            update(l + 1, val);
            update(r + 2, val);
        }
    };

    int getLCA(int u, int v, vector<int>& depth, vector<vector<int>>& up) {
        int LOG = up.size();

        if (depth[u] < depth[v]) {
            swap(u, v);
        }

        int diff = depth[u] - depth[v];

        for (int j = 0; j < LOG; j++) {
            if (diff & (1 << j)) {
                u = up[j][u];
            }
        }

        if (u == v) return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[j][u] != up[j][v]) {
                u = up[j][u];
                v = up[j][v];
            }
        }

        return up[0][u];
    }

    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // 1. Iterative DFS: parent, depth and Euler Tour
        vector<int> parent(n, 0), depth(n, 0);
        vector<int> tin(n), tout(n), subtree(n, 1);
        vector<int> order, st;

        st.push_back(0);

        while (!st.empty()) {
            int u = st.back();
            st.pop_back();

            tin[u] = order.size();
            order.push_back(u);

            for (int v : adj[u]) {
                if (v == parent[u]) continue;

                parent[v] = u;
                depth[v] = depth[u] + 1;
                st.push_back(v);
            }
        }

        // Calculate subtree sizes and ending Euler indices
        for (int i = n - 1; i > 0; i--) {
            int u = order[i];
            subtree[parent[u]] += subtree[u];
        }

        for (int u = 0; u < n; u++) {
            tout[u] = tin[u] + subtree[u] - 1;
        }

        // 2. Binary lifting for LCA
        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n));

        for (int u = 0; u < n; u++) {
            up[0][u] = parent[u];
        }

        for (int j = 1; j < LOG; j++) {
            for (int u = 0; u < n; u++) {
                up[j][u] = up[j - 1][up[j - 1][u]];
            }
        }

        // 3. Initial root-to-node XOR masks
        vector<int> pref(n, 0);

        for (int u : order) {
            int mask = 1 << (s[u] - 'a');

            if (u == 0) {
                pref[u] = mask;
            } else {
                pref[u] = pref[parent[u]] ^ mask;
            }
        }

        Fenwick fw(n);
        vector<bool> answer;

        // 4. Process queries
        for (string& q : queries) {
            string type;
            stringstream ss(q);
            ss >> type;

            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;

                int oldMask = 1 << (s[u] - 'a');
                int newMask = 1 << (c - 'a');
                int delta = oldMask ^ newMask;

                // This change affects root-prefix masks
                // of every node in u's subtree.
                fw.rangeUpdate(tin[u], tout[u], delta);

                s[u] = c;
            } else {
                int u, v;
                ss >> u >> v;

                int w = getLCA(u, v, depth, up);

                int prefixU =
                    pref[u] ^ fw.query(tin[u] + 1);

                int prefixV =
                    pref[v] ^ fw.query(tin[v] + 1);

                // Parity mask of the complete path
                int mask = prefixU ^ prefixV;
                mask ^= (1 << (s[w] - 'a'));

                // At most one character may have odd frequency
                answer.push_back((mask & (mask - 1)) == 0);
            }
        }

        return answer;
    }
};