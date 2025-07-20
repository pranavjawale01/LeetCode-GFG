class Solution {
public:
    #define p pair<int, pair<int, int>>
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
        ans[0][0] = 0;
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, {0, 0}});
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int d = curr.first;
            int i = curr.second.first;
            int j = curr.second.second;
            for (auto &dir : dirs) {
                int x = i + dir[0];
                int y = j + dir[1];
                if (x < 0 || x >= m || y < 0 || y >= n) continue;
                int wt = (grid[x][y] == 1) ? 1 : 0;
                if (d + wt < ans[x][y]) {
                    ans[x][y] = d + wt;
                    pq.push({d + wt, {x, y}});
                }
            }
        }
        return ans[m-1][n-1];
    }
};