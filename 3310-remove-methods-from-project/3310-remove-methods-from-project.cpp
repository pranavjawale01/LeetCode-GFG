class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<int> &vis) {
        vis[node] = 1;
        for (auto &x : adj[node]) {
            if (!vis[x]) {
                dfs(x, adj, vis);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> adj[n];
        for (auto x : invocations) {
            adj[x[0]].push_back(x[1]);
        }
        vector<int> vis(n, 0);
        dfs(k, adj, vis);

        bool suspicious = true;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                for (auto x : adj[i]) {
                    if (vis[x]) {
                        suspicious = false;
                    }
                }
            }
        }
        vector<int> ans;
        if (suspicious) {
            for (int i = 0; i < n; i++) {
                if (!vis[i]) {
                    ans.push_back(i);
                }
            }
        } else {
            for (int i = 0; i < n; i++) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};








// TLE
// class Solution {
// public:
//     vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
//         unordered_set<int> bug;
//         bug.insert(k);
//         bool flag;
//         do {
//             flag = false;
//             for (auto &x : invocations) {
//                 int a = x[0], b = x[1];
//                 if (bug.count(a) && !bug.count(b)) {
//                     bug.insert(b);
//                     flag = true;
//                 }
//             }
//         } while (flag);
//         for (auto &x : invocations) {
//             int a = x[0], b = x[1];
//             if (!bug.count(a) && bug.count(b)) {
//                 vector<int> ans;
//                 for (int i = 0; i < n; i++) ans.push_back(i);
//                 return ans;
//             }
//         }
//         vector<int> ans;
//         for (int i = 0; i < n; i++) {
//             if (!bug.count(i)) ans.push_back(i);
//         }
//         return ans;
//     }
// };