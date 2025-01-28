class Solution {
public:
    int m, n;
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int bfs(int i, int j, vector<vector<int>> &grid) {
        queue<pair<int, int>> q;
        q.push({i, j});
        int fishCount = grid[i][j];
        grid[i][j] = 0;
        while (!q.empty()) {
            i = q.front().first;
            j = q.front().second;
            q.pop();
            for (auto &d : dirs) {
                int x = d[0] + i;
                int y = d[1] + j;
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] > 0) {
                    q.push({x, y});
                    fishCount += grid[x][y];
                    grid[x][y] = 0;
                }
            }
        }
        return fishCount;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int fish = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    fish = max(fish, bfs(i, j, grid));
                }
            }
        }
        return fish;
    }
};