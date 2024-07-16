class Solution {
public:
    typedef pair<int, pair<int, int>> p;

    vector<vector<int>> dirs = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();

        priority_queue<p, vector<p>, greater<p>> pq;

        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

        auto isSafe = [&](int x, int y) {
            return x >= 0 && x < n && y >= 0 && y < m;
        };

        pq.push({0, {0, 0}});
        dp[0][0] = 0;

        while (!pq.empty()) {
            int diff = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if (x == n - 1 && y == m - 1) {
                return diff;
            }

            for (auto dir : dirs) {
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if (isSafe(x_, y_)) {
                    int newDiff = max(diff, abs(heights[x][y] - heights[x_][y_]));
                    if (dp[x_][y_] > newDiff) {
                        dp[x_][y_] = newDiff;
                        pq.push({newDiff, {x_, y_}});
                    }
                }
            }
        }

        return dp[n-1][m-1];
    }
};