class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> mp;
        vector<int> indegree(numCourses, 0);
        for (auto &x : prerequisites) {
            int u = x[0], v = x[1];
            mp[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }
        unordered_map<int, unordered_set<int>> check;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto &x : mp[node]) {
                check[x].insert(node);
                for (auto &pre : check[node]) {
                    check[x].insert(pre);
                }
                indegree[x]--;
                if (indegree[x] == 0) q.push(x);
            }
        }
        int qq = queries.size();
        vector<bool> ans(qq, false);
        for (int i = 0; i < qq; i++) {
            int s = queries[i][0], e = queries[i][1];
            ans[i] = check[e].contains(s);
        }
        return ans;
    }
};





// class Solution {
// public:
//     unordered_map<int, vector<int>> mp;

//     bool solve(int s, int e, vector<bool> &vis) {
//         vis[s] = true;
//         if (s == e) return true;
//         bool reachable = false;
//         for (auto &x : mp[s]) {
//             if (!vis[x]) {
//                 reachable |= solve(x, e, vis);
//             }
//         }
//         return reachable;
//     }

//     void help(int numCourses, vector<vector<bool>> &check) {
//         for (int i = 0; i < numCourses; i++) {
//             for (int j = 0; j < numCourses; j++) {
//                 if (i != j) {
//                     vector<bool> vis(numCourses, false);
//                     if (solve(i, j, vis)) {
//                         check[i][j] = true;
//                     }
//                 }
//             }
//         }
//     }

//     vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
//         for (auto &x : prerequisites) {
//             mp[x[0]].push_back(x[1]);
//         }
//         vector<vector<bool>> check(numCourses, vector<bool>(numCourses, false));
//         help(numCourses, check);
//         int q = queries.size();
//         vector<bool> ans(q);
//         for (int i = 0; i < q; i++) {
//             int u = queries[i][0], v = queries[i][1];
//             ans[i] = check[u][v];
//         }
//         return ans;
//     }
// };










// // class Solution {
// // public:
// //     bool solve(unordered_map<int, vector<int>> &mp, int s, int e, vector<bool> &vis) {
// //         vis[s] = true;
// //         if (s == e) return true;
// //         bool reachable = false;
// //         for (auto &x : mp[s]) {
// //             if (!vis[x]) {
// //                 reachable |= solve(mp, x, e, vis);
// //             }
// //         }
// //         return reachable;
// //     }
// //     vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
// //         unordered_map<int, vector<int>> mp;
// //         for (auto &x : prerequisites) {
// //             mp[x[0]].push_back(x[1]);
// //         }
// //         int q = queries.size();
// //         vector<bool> ans(q);
// //         for (int i = 0; i < q; i++) {
// //             int u = queries[i][0];
// //             int v = queries[i][1];
// //             vector<bool> vis(numCourses, false);
// //             ans[i] = solve(mp, u, v, vis);
// //         }
// //         return ans;
// //     }
// // };






// // // TLE
// // // class Solution {
// // // public:
// // //     vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
// // //         int n = prerequisites.size();
// // //         int m = queries.size();
// // //         if (n == 0) {
// // //             return vector<bool>(m, false);
// // //         }
// // //         unordered_map<int, vector<int>> mp;
// // //         for (int i = 0; i < n; i++) {
// // //             mp[prerequisites[i][0]].push_back(prerequisites[i][1]);
// // //         }
// // //         vector<bool> ans(m, true);
// // //         function<bool(int, int)> solve = [&](int a, int b) {
// // //             for (int x : mp[a]) {
// // //                 if (x == b) {
// // //                     return true;
// // //                 }
// // //                 if (solve(x, b)) {
// // //                     return true;
// // //                 }
// // //             }
// // //             return false;
// // //         };
// // //         for (int i = 0; i < m; i++) {
// // //             int u = queries[i][0];
// // //             int v = queries[i][1];
// // //             ans[i] = solve(u, v);
// // //         }
// // //         return ans;
// // //     }
// // // };