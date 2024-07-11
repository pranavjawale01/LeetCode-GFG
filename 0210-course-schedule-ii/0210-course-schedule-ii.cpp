class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> mp;
        vector<int> indegree(numCourses, 0);

        for (auto x : prerequisites) {
            mp[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }

        queue<int> q;
        vector<int> ans;
        int count = 0;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                count++;
                ans.push_back(i);
            }
        }

        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int y : mp[x]) {
                indegree[y]--;
                if (indegree[y] == 0) {
                    q.push(y);
                    count++;
                    ans.push_back(y);
                }
            }
        }

        if (count != numCourses) {
            return {};
        }

        return ans;
    }
};