class Solution {
public:
    bool isCyclic(unordered_map<int, vector<int>> &mp, int v, vector<bool> &vis, vector<bool> &rec) {
        if (rec[v]) return true;
        if (vis[v]) return false;
        vis[v] = rec[v] = true;
        for (int x : mp[v]) {
            if (isCyclic(mp, x, vis, rec)) return true;
        }
        rec[v] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> mp;
        int n = numCourses;
        vector<bool> vis(n, false);
        vector<bool> rec(n, false);
        for (auto &x : prerequisites) {
            mp[x[1]].push_back(x[0]);
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i] && isCyclic(mp, i, vis, rec)) {
                return false;
            }
        }
        return true;
    }
};








// class Solution {
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<int> indegree(numCourses, 0);
//         map<int, vector<int>> mp;
        
//         for (auto& pre : prerequisites) {
//             int course = pre[0];
//             int prerequisite = pre[1];
//             mp[prerequisite].push_back(course);
//             indegree[course]++;
//         }
        
//         queue<int> q;
//         int count = 0;
        
//         for (int i = 0; i < numCourses; i++) {
//             if (indegree[i] == 0) {
//                 q.push(i);
//                 count++;
//             }
//         }
        
//         while (!q.empty()) {
//             int curr = q.front();
//             q.pop();
//             for (int next : mp[curr]) {
//                 indegree[next]--;
//                 if (indegree[next] == 0) {
//                     q.push(next);
//                     count++;
//                 }
//             }
//         }
        
//         return count == numCourses;
//     }
// };