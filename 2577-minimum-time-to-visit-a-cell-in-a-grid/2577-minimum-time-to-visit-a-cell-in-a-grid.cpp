class Solution {
public:
    #define p pair<int, int>
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<p> q;
        q.push({0, 0});
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int time = 1;
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                auto curr = q.front();
                q.pop();
                int i = curr.first;
                int j = curr.second;
                if (((i + 1) == n) && ((j + 1) == m)) return time - 1;
                for (auto x : dirs) {
                    int xi = i + x[0];
                    int yj = j + x[1];
                    if (xi >= 0 && xi < n && yj >= 0 && yj < m) {
                        if (grid[xi][yj] <= time) {
                            q.push({xi, yj});
                        }
                    }
                }
            }
            time++;
        }
        return -1;
    }
};