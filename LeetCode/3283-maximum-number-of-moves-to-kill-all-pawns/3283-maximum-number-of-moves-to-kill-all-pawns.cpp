class Solution {
public:
    vector<vector<int>> dirs = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
    
    void BFS(int x, int y, int idx, vector<vector<int>> &minDist, vector<vector<int>> &pos) {
        vector<vector<int>> dist(50, vector<int>(50, -1));
        queue<pair<int, int>> q;
        q.push({x, y});
        dist[x][y] = 0;
        while (!q.empty()) {
            auto [currX, currY] = q.front();
            q.pop();
            for (auto &dir : dirs) {
                int newX = currX + dir[0];
                int newY = currY + dir[1];
                if (newX >= 0 && newX < 50 && newY >= 0 && newY < 50 && dist[newX][newY] == -1) {
                    dist[newX][newY] = dist[currX][currY] + 1;
                    q.push({newX, newY});
                }
            }
        }
        for (int i = 0; i < pos.size(); i++) {
            int x_ = pos[i][0];
            int y_ = pos[i][1];
            minDist[idx][i] = dist[x_][y_];
        }
    }

    int solve(vector<vector<int>> &minDist, int idx, int mask, int n, bool Alice, vector<vector<vector<int>>> &dp) {
        if (mask == 0) {
            return 0;
        }
        if (dp[idx][mask][Alice] != -1) {
            return dp[idx][mask][Alice];
        }
        int result = Alice ? -1 : 1e9;
        for (int i = 1; i < n; i++) {
            if (mask & (1 << (i - 1))) {
                int moves = minDist[idx][i];
                if (Alice) {
                    result = max(result, moves + solve(minDist, i, mask ^ (1 << (i - 1)), n, !Alice, dp));
                } else {
                    result = min(result, moves + solve(minDist, i, mask ^ (1 << (i - 1)), n, !Alice, dp));
                }
            }
        }
        return dp[idx][mask][Alice] = result;
    }
    
    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        int n = positions.size();
        vector<vector<int>> pos;
        pos.push_back({kx, ky});
        for (auto vec : positions) {
            pos.push_back({vec[0], vec[1]});
        }
        vector<vector<int>> minDist(pos.size(), vector<int>(pos.size(), 0));
        for (int i = 0; i < pos.size(); i++) {
            int x = pos[i][0];
            int y = pos[i][1];
            BFS(x, y, i, minDist, pos);
        }
        bool Alice = true;
        vector<vector<vector<int>>> dp(pos.size(), vector<vector<int>>(1 << n, vector<int>(2, -1)));
        return solve(minDist, 0, (1 << n) - 1, pos.size(), Alice, dp);
    }
};