class Solution {
public:
    int bfs(int start, unordered_map<int, vector<int>> &mp, vector<bool> &vis) {
        queue<pair<int, int>> q;
        q.push({start, 0});
        int maxDist = 0;
        while (!q.empty()) {
            auto [curr, dist] = q.front();
            q.pop();
            for (int &x : mp[curr]) {
                if (!vis[x]) {
                    vis[x] = true;
                    q.push({x, dist + 1});
                    maxDist = max(maxDist, dist + 1);
                }
            }
        }
        return maxDist;
    }
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[favorite[i]].push_back(i);
        }
        int longestCycleEmplCount = 0;
        int happyCoupleEmplCount = 0;
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                unordered_map<int, int> mp1;
                int currNode = i;
                int currNodeCount = 0;
                while (!vis[currNode]) {
                    vis[currNode] = true;
                    mp1[currNode] = currNodeCount;
                    int nextNode = favorite[currNode];
                    currNodeCount++;
                    if (mp1.count(nextNode)) {
                        int cycleLength = currNodeCount - mp1[nextNode];
                        longestCycleEmplCount = max(longestCycleEmplCount, cycleLength);
                        if (cycleLength == 2) {
                            vector<bool> visited(n, false);
                            visited[currNode] = true;
                            visited[nextNode] = true;
                            happyCoupleEmplCount += 2 + bfs(currNode, mp, visited) + bfs(nextNode, mp, visited);
                        }
                        break;
                    }
                    currNode = nextNode;
                }
            }
        }
        return max(happyCoupleEmplCount, longestCycleEmplCount);
    }
};