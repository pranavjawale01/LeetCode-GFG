class DSU {
public:
    vector<int> parent;
    vector<int> rank;

    DSU(int n) {
        parent.resize(n+1);
        rank.resize(n+1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    
    int find(int x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int xpar = find(x);
        int ypar = find(y);
        if (xpar == ypar) {
            return;
        }
        if (rank[xpar] > rank[ypar]) {
            parent[ypar] = xpar;
        } else if (rank[ypar] > rank[xpar]) {
            parent[xpar] = ypar;
        } else {
            parent[ypar] = xpar;
            rank[xpar]++;
        }
    }
};
    
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);
        for (auto &x : edges) {
            int u = x[0], v = x[1];
            if (dsu.find(u) == dsu.find(v)) {
                return x;
            }
            dsu.Union(u, v);
        }
        return {};
    }
};






// class Solution {
// public:
//     int n;
//     bool bfs(unordered_map<int, vector<int>> &mp, int u, int v) {
//         vector<bool> vis(n + 1, false);
//         queue<int> q;
//         q.push(u);
//         while (!q.empty()) {
//             int curr = q.front();
//             q.pop();
//             vis[curr] = true;
//             if (curr == v) return true;
//             for (int &x : mp[curr]) {
//                 if (!vis[x]) q.push(x);
//             }
//         }
//         return false;
//     }

//     vector<int> findRedundantConnection(vector<vector<int>>& edges) {
//         n = edges.size();
//         unordered_map<int, vector<int>> mp;
//         for (auto &x : edges) {
//             int u = x[0], v = x[1];
//             if (mp.count(u) && mp.count(v) && bfs(mp, u, v)) {
//                 return x;
//             }
//             mp[u].push_back(v);
//             mp[v].push_back(u);
//         }
//         return {};
//     }
// };








// // class Solution {
// // public:
// //     bool dfs(unordered_map<int, vector<int>> &mp, int u, int v, vector<bool> &vis) {
// //         vis[u] = true;
// //         if (u == v) return true;
// //         for (auto &x : mp[u]) {
// //             if (vis[x]) continue;
// //             if (dfs(mp, x, v, vis)) return true;
// //         }
// //         return false;
// //     }

// //     vector<int> findRedundantConnection(vector<vector<int>>& edges) {
// //         int n = edges.size();
// //         unordered_map<int, vector<int>> mp;
// //         for (auto &x : edges) {
// //             int u = x[0], v = x[1];
// //             vector<bool> vis(n + 1, false);
// //             if (mp.count(u) && mp.count(v) && dfs(mp, u, v, vis)) {
// //                 return x;
// //             }
// //             mp[u].push_back(v);
// //             mp[v].push_back(u);
// //         }
// //         return {};
// //     }
// // };