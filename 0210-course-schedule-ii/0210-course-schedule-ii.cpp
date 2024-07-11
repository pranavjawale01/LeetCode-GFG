class Solution {
public:
    bool cycleDetected = false;

    void dfs(unordered_map<int, vector<int>>& mp, int u, vector<bool>& vis, vector<bool>& rec, stack<int>& st) {
        vis[u] = true;
        rec[u] = true;
        for (int v : mp[u]) {
            if (rec[v]) {
                cycleDetected = true;
                return;
            }
            if (!vis[v]) {
                dfs(mp, v, vis, rec, st);
                if (cycleDetected) return;
            }
        }
        st.push(u);
        rec[u] = false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> mp;
        for (auto& x : prerequisites) {
            mp[x[1]].push_back(x[0]);
        }
        
        vector<bool> rec(numCourses, false);
        vector<bool> vis(numCourses, false);
        stack<int> st;

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                dfs(mp, i, vis, rec, st);
                if (cycleDetected) return {};
            }
        }

        vector<int> result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        return result;
    }
};



// class Solution {
// public:
//     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//         map<int, vector<int>> mp;
//         vector<int> indegree(numCourses, 0);

//         for (auto x : prerequisites) {
//             mp[x[1]].push_back(x[0]);
//             indegree[x[0]]++;
//         }

//         queue<int> q;
//         vector<int> ans;
//         int count = 0;

//         for (int i = 0; i < numCourses; i++) {
//             if (indegree[i] == 0) {
//                 q.push(i);
//                 count++;
//                 ans.push_back(i);
//             }
//         }

//         while (!q.empty()) {
//             int x = q.front();
//             q.pop();
//             for (int y : mp[x]) {
//                 indegree[y]--;
//                 if (indegree[y] == 0) {
//                     q.push(y);
//                     count++;
//                     ans.push_back(y);
//                 }
//             }
//         }

//         if (count != numCourses) {
//             return {};
//         }

//         return ans;
//     }
// };