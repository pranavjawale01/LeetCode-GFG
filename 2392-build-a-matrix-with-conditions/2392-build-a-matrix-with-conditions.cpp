class Solution {
public:
    void dfs(int node, unordered_map<int, vector<int>> &adj, vector<int> &vis, stack<int> &st, bool &hasCycle) {
        vis[node] = 1;
        for (int &x : adj[node]) {
            if (vis[x] == 0) {
                dfs(x, adj, vis, st, hasCycle);
            } else if (vis[x] == 1) {
                hasCycle = true;
                return;
            }
        }
        vis[node] = 2;
        st.push(node);
    }
    vector<int> topoSort(vector<vector<int>> &edges, int n) {
        unordered_map<int, vector<int>> adj;
        stack<int> st;
        vector<int> order;
        vector<int> vis(n+1, 0);
        bool hasCycle = false;
        for (vector<int> &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        for (int i = 1; i <= n; i++) {
            if (vis[i] == 0) {
                dfs(i, adj, vis, st, hasCycle);
                if (hasCycle) {
                    return {};
                }
            }
        }
        while (!st.empty()) {
            order.push_back(st.top());
            st.pop();
        }
        return order;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> orderRows = topoSort(rowConditions, k);
        vector<int> orderCols = topoSort(colConditions, k);

        if (orderRows.empty() || orderCols.empty()) {
            return {};
        }

        vector<vector<int>> matrix(k, vector<int>(k, 0));

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (orderRows[i] == orderCols[j]) {
                    matrix[i][j] = orderRows[i];
                }
            }
        }

        return matrix;
    }
};