class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        vector<int> indegree(n);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            indegree[edges[i][1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        set<int> st[n];
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (auto it : adj[curr]) {
                st[it].insert(curr);
                for (auto x : st[curr]) {
                    st[it].insert(x);
                }
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        vector<vector<int>> ans(n, vector<int>());
        for (int i = 0; i < n; i++) {
            ans[i] = vector<int>(st[i].begin(), st[i].end());
        }
        return ans;
    }
};





// class Solution {
// public:
//     vector<vector<int>> ans;
//     void solve(unordered_map<int, vector<int>> &mp, int node, vector<int> &temp, vector<bool> &vis) {
//         if (vis[node]) {
//             return;
//         }
//         vis[node] = true;
//         for (auto x : mp[node]) {
//             if (!vis[x]) {
//                 temp.push_back(x);
//                 solve(mp, x, temp, vis);
//             }
//         }
//     }
//     vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
//         unordered_map<int, vector<int>> mp;
//         ans.resize(n);
//         for (auto edge : edges) {
//             mp[edge[1]].push_back(edge[0]);
//         }
//         for (int i = 0; i < n; i++) {
//             vector<int> temp;
//             vector<bool> visited(n, false);
//             solve(mp, i, temp, visited);
//             sort(temp.begin(), temp.end());
//             ans[i] = temp;
//         }
//         return ans;
//     }
// };