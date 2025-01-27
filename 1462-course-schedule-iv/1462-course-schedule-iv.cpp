class Solution {
public:
    bool solve(unordered_map<int, vector<int>> &mp, int s, int e, vector<bool> &vis) {
        vis[s] = true;
        if (s == e) return true;
        bool reachable = false;
        for (auto &x : mp[s]) {
            if (!vis[x]) {
                reachable |= solve(mp, x, e, vis);
            }
        }
        return reachable;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> mp;
        for (auto &x : prerequisites) {
            mp[x[0]].push_back(x[1]);
        }
        int q = queries.size();
        vector<bool> ans(q);
        for (int i = 0; i < q; i++) {
            int u = queries[i][0];
            int v = queries[i][1];
            vector<bool> vis(numCourses, false);
            ans[i] = solve(mp, u, v, vis);
        }
        return ans;
    }
};






// TLE
// class Solution {
// public:
//     vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
//         int n = prerequisites.size();
//         int m = queries.size();
//         if (n == 0) {
//             return vector<bool>(m, false);
//         }
//         unordered_map<int, vector<int>> mp;
//         for (int i = 0; i < n; i++) {
//             mp[prerequisites[i][0]].push_back(prerequisites[i][1]);
//         }
//         vector<bool> ans(m, true);
//         function<bool(int, int)> solve = [&](int a, int b) {
//             for (int x : mp[a]) {
//                 if (x == b) {
//                     return true;
//                 }
//                 if (solve(x, b)) {
//                     return true;
//                 }
//             }
//             return false;
//         };
//         for (int i = 0; i < m; i++) {
//             int u = queries[i][0];
//             int v = queries[i][1];
//             ans[i] = solve(u, v);
//         }
//         return ans;
//     }
// };