class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        map<int, vector<int>> mp;
        
        for (auto& pre : prerequisites) {
            int course = pre[0];
            int prerequisite = pre[1];
            mp[prerequisite].push_back(course);
            indegree[course]++;
        }
        
        queue<int> q;
        int count = 0;
        
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                count++;
            }
        }
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int next : mp[curr]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.push(next);
                    count++;
                }
            }
        }
        
        return count == numCourses;
    }
};