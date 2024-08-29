class DSU {
    vector<int> rank, parent, size;
public:
    DSU(int n) {
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = find(parent[node]);
    }

    void unionByRank(int u, int v) {
        int u_parent = find(u);
        int v_parent = find(v);
        if (u_parent == v_parent) {
            return;
        }
        if (rank[u_parent] < rank[v_parent]) {
            parent[u_parent] = v_parent;
        } else if (rank[v_parent] < rank[u_parent]) {
            parent[v_parent] = u_parent;
        } else {
            parent[v_parent] = u_parent;
            rank[u_parent]++;
        }
    }

    void unionBySize(int u, int v) {
        int u_parent = find(u);
        int v_parent = find(v);
        if (u_parent == v_parent) {
            return;
        }
        if (size[u_parent] < size[v_parent]) {
            parent[u_parent] = v_parent;
            size[v_parent] += size[u_parent];
        } else {
            parent[v_parent] = u_parent;
            size[u_parent] += size[v_parent];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0;
        int maxCol = 0;
        for (auto x : stones) {
            maxRow = max(maxRow, x[0]);
            maxCol = max(maxCol, x[1]);
        }
        DSU ds(maxRow + maxCol + 1);
        unordered_map<int, int> mp;
        for (auto x : stones) {
            int nodeRow = x[0];
            int nodeCol = x[1];
            ds.unionBySize(nodeRow, nodeCol);
            mp[nodeRow] = 1;
            mp[nodeCol] = 1;
        }
        int count = 0;
        for (auto x : mp) {
            if (ds.find(x.first) == x.first) {
                count++;
            }
        }
        return stones.size() - count;
    }
};












// class Solution {
// public:
//     int n;
//     void dfs(vector<vector<int>> &stones, int idx, vector<bool> &vis) {
//         vis[idx] = true;
//         for (int i = 0; i < n; i++) {
//             if (!vis[i] && ((stones[i][0] == stones[idx][0]) || stones[i][1] == stones[idx][1])) {
//                 dfs(stones, i, vis);
//             }
//         }
//     }
//     int removeStones(vector<vector<int>>& stones) {
//         n = stones.size();
//         vector<bool> vis(n, false);
//         int count = 0;
//         for (int i = 0; i < n; i++) {
//             if (vis[i]) {
//                 continue;
//             }
//             dfs(stones, i, vis);
//             count++;
//         }
//         return n - count;
//     }
// };