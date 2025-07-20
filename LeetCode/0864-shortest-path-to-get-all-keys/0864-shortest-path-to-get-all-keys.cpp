class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int totalKeys = 0;
        int startX, startY;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '@') {
                    startX = i;
                    startY = j;
                } else if (islower(grid[i][j])) {
                    totalKeys |= (1 << (grid[i][j] - 'a'));
                }
            }
        }

        vector<int> dirx = {0, 0, 1, -1};
        vector<int> diry = {1, -1, 0, 0};

        queue<tuple<int, int, int>> q;
        q.push({startX, startY, 0});
        
        vector<vector<vector<bool>>> vis(m, vector<vector<bool>>(n, vector<bool>(1 << 6, false)));
        vis[startX][startY][0] = true;

        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [x, y, keys] = q.front();
                q.pop();

                if (keys == totalKeys) {
                    return level;
                }

                for (int i = 0; i < 4; ++i) {
                    int newx = x + dirx[i];
                    int newy = y + diry[i];

                    if (newx < 0 || newy < 0 || newx >= m || newy >= n) {
                        continue;
                    }

                    char cell = grid[newx][newy];
                    if (cell == '#') {
                        continue;
                    }

                    if (isupper(cell) && !(keys & (1 << (cell - 'A')))) {
                        continue;
                    }

                    int newKeys = keys;
                    if (islower(cell)) {
                        newKeys |= (1 << (cell - 'a'));
                    }

                    if (!vis[newx][newy][newKeys]) {
                        vis[newx][newy][newKeys] = true;
                        q.push({newx, newy, newKeys});
                    }
                }
            }
            ++level;
        }

        return -1;
    }
};