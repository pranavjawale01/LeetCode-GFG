class Solution {
public:
    typedef pair<int, pair<int, int>> pp;
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();
        priority_queue<pp, vector<pp>, greater<>> pq;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            pq.push({heightMap[i][0], {i, 0}});
            vis[i][0] = true;
            pq.push({heightMap[i][n-1], {i, n-1}});
            vis[i][n-1] = true;
        }
        for (int i = 0; i < n; i++) {
            pq.push({heightMap[0][i], {0, i}});
            vis[0][i] = true;
            pq.push({heightMap[m-1][i], {m-1, i}});
            vis[m-1][i] = true;
        }
        int ans = 0;
        while (!pq.empty()) {
            auto [height, cell] = pq.top();
            pq.pop();
            int i = cell.first, j = cell.second;
            for (auto dir : dirs) {
                int x = i + dir[0];
                int y = j + dir[1];
                if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y]) {
                    ans += max(0, height - heightMap[x][y]);
                    pq.push({max(height, heightMap[x][y]), {x, y}});
                    vis[x][y] = true;
                }
            }
        }
        return ans;
    }
};