class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, queue<pair<int, int>>& q) {
        int n = grid.size();
        if (i < 0 || j < 0 || i >= n || j >= n || grid[i][j] != 1) {
            return;
        }
        grid[i][j] = 2;
        q.push({i, j});
        dfs(grid, i+1, j, q);
        dfs(grid, i-1, j, q);
        dfs(grid, i, j+1, q);
        dfs(grid, i, j-1, q);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (found) {
                break;
            }
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, q);
                    found = true;
                    break;
                }
            }
        }
        int steps = 0;
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [x, y] = q.front();
                q.pop();
                for (auto &dir : dirs) {
                    int nx = x + dir[0];
                    int ny = y + dir[1];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                        if (grid[nx][ny] == 1) {
                            return steps;
                        }
                        if (grid[nx][ny] == 0) {
                            grid[nx][ny] = 2;
                            q.push({nx, ny});
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};