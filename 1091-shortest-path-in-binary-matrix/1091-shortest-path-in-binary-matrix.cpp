class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n-1][n-1] != 0) {
            return -1;
        }
        queue<pair<int, int>> q;
        q.push({0, 0});
        int level = 1;
        grid[0][0] = 1;
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                pair<int, int> temp = q.front();
                q.pop();
                if (temp.first == n - 1 && temp.second == n - 1) {
                    return level;
                }
                for (int i = -1; i <= 1; i++) {
                    for (int j = -1; j <= 1; j++) {
                        int x = temp.first + i;
                        int y = temp.second + j;
                        if (x < 0 || y < 0 || x >= n || y >= n || grid[x][y] != 0) {
                            continue;
                        }
                        q.push({x, y});
                        grid[x][y] = 1;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};