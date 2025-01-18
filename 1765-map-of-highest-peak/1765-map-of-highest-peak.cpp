class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> height(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    height[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                pair<int, int> curr = q.front();
                q.pop();
                int i = curr.first;
                int j = curr.second;
                for (auto &dir : dirs) {
                    int x = i + dir[0];
                    int y = j + dir[1];
                    if (x >= 0 && y >= 0 && x < m && y < n && height[x][y] == -1) {
                        height[x][y] = height[i][j] + 1;
                        q.push({x, y});
                    }
                }
            }
        }
        return height;
    }
};