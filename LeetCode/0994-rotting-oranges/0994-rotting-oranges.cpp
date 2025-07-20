class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        queue<pair<int, int>> q;
        int n = grid.size(), m = grid[0].size();
        int total = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) q.push({i, j});
                if (grid[i][j]) total++;
            }
        }

        int count = 0;
        int days = 0;

        while (!q.empty()) {
            int k = q.size();
            count += k;

            while (k--) {
                pair<int, int> top = q.front();
                q.pop();

                for (auto &dir : dirs) {
                    int x = dir[0] + top.first;
                    int y = dir[1] + top.second;

                    if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1) {
                        grid[x][y] = 2;
                        q.push({x, y});
                    }
                }
            }

            if (!q.empty()) {
                days++;
            }
        }

        return count == total ? days : -1;
    }
};