class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int n;

    int find(int i) {
        if (parent[i] != i) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }

    void Union(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);
        if (root_u != root_v) {
            if (rank[root_u] > rank[root_v]) {
                parent[root_v] = root_u;
            } else if (rank[root_u] < rank[root_v]) {
                parent[root_u] = root_v;
            } else {
                parent[root_v] = root_u;
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        n = stones.size();
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    Union(i, j);
                }
            }
        }
        int groups = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i) {
                groups++;
            }
        }
        return n - groups;
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