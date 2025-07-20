class Solution {
public:
    bool isBipartite(unordered_map<int, vector<int>> &mp, int curr, vector<int> &colors, int currColor) {
        colors[curr] = currColor;
        for (int x : mp[curr]) {
            if (colors[x] == colors[curr]) {
                return false;
            }
            if (colors[x] == -1) {
                if (isBipartite(mp, x, colors, 1 - currColor) == false) {
                    return false;
                }
            }
        }
        return true;
    }

    int bfs(unordered_map<int, vector<int>> &mp, int currNode, int n) {
        queue<int> q;
        vector<bool> vis(n, false);
        q.push(currNode);
        vis[currNode] = true;
        int level = 1;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int curr = q.front();
                q.pop();
                for (int x : mp[curr]) {
                    if (vis[x]) continue;
                    q.push(x);
                    vis[x] = true;
                }
            }
            level++;
        }
        return level - 1;
    }

    int maxGroupFromEachComp(unordered_map<int, vector<int>> &mp, int curr, vector<bool> &vis, vector<int> &levels) {
        int maxGrp = levels[curr];
        vis[curr] = true;
        for (int x : mp[curr]) {
            if (!vis[x]) {
                maxGrp = max(maxGrp, maxGroupFromEachComp(mp, x, vis, levels));
            }
        }
        return maxGrp;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> mp;
        for (auto &x : edges) {
            mp[x[0] - 1].push_back(x[1] - 1);
            mp[x[1] - 1].push_back(x[0] - 1);
        }
        
        // Step 1: Check if the graph is bipartite
        vector<int> colors(n, -1);
        for (int node = 0; node < n; node++) {
            if (colors[node] == -1) {
                if (isBipartite(mp, node, colors, 1) == false) {
                    return -1;
                }
            }
        }
        
        // Step 2: Find levels for each node using BFS
        vector<bool> vis(n, false);
        vector<int> levels(n, 0);
        for (int node = 0; node < n; node++) {
            levels[node] = bfs(mp, node, n);
        }

        // Step 3: Calculate the maximum group size from each connected component
        int maxGroupEachComp = 0;
        vis.assign(n, false);
        for (int node = 0; node < n; node++) {
            if (!vis[node]) {
                maxGroupEachComp += maxGroupFromEachComp(mp, node, vis, levels);
            }
        }
        return maxGroupEachComp;
    }
};