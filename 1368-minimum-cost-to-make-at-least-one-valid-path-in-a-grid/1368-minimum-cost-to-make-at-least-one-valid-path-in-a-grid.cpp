class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int m, n;
    vector<vector<bool>> vis;

    int dfs(int i, int j, vector<vector<int>> &grid, int cost) {
        if (i == m - 1 && j == n - 1) {
            return cost;
        }
        vis[i][j] = true;
        int minCost = INT_MAX;
        for (int dir = 0; dir < 4; dir++) {
            int x = i + dirs[dir][0];
            int y = j + dirs[dir][1];
            if (x >= 0 && y >= 0 && x < m && y < n && !vis[x][y]) {
                int nextCost = cost + ((grid[i][j] - 1 != dir) ? 1 : 0);
                minCost = min(minCost, dfs(x, y, grid, nextCost));
            }
        }
        vis[i][j] = false;
        return minCost;
    }

    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vis.resize(m, vector<bool>(n, false));
        return dfs(0, 0, grid, 0);
    }
};