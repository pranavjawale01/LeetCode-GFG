class Solution {
public:
    int knightMoves(int x1, int y1, int x2, int y2) {
        vector<vector<int>> directions = {
            {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
            {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
        };
        
        vector<vector<int>> dist(50, vector<int>(50, -1));
        dist[x1][y1] = 0;
        
        queue<pair<int, int>> q;
        q.push({x1, y1});
        
        while (!q.empty()) {
            auto [cx, cy] = q.front(); q.pop();
            int curDist = dist[cx][cy];
            
            for (auto dir : directions) {
                int nx = cx + dir[0], ny = cy + dir[1];
                if (nx >= 0 && ny >= 0 && nx < 50 && ny < 50 && dist[nx][ny] == -1) {
                    dist[nx][ny] = curDist + 1;
                    q.push({nx, ny});
                }
            }
        }
        
        return dist[x2][y2];
    }

    int solve(int kx, int ky, vector<vector<int>>& positions, int mask, vector<vector<int>>& dp) {
        int n = positions.size();
        if (mask == (1 << n) - 1) {
            return 0;
        }
        
        if (dp[mask][kx * 50 + ky] != -1) {
            return dp[mask][kx * 50 + ky];
        }
        
        int maxTotalMoves = 0;
        for (int i = 0; i < n; ++i) {
            if (!(mask & (1 << i))) {
                int px = positions[i][0], py = positions[i][1];
                int movesToCapture = knightMoves(kx, ky, px, py);                
                int futureMoves = solve(px, py, positions, mask | (1 << i), dp);                
                maxTotalMoves = max(maxTotalMoves, movesToCapture + futureMoves);
            }
        }
        
        dp[mask][kx * 50 + ky] = maxTotalMoves;
        return maxTotalMoves;
    }

    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        int n = positions.size();
        vector<vector<int>> dp(1 << n, vector<int>(2500, -1));        
        return solve(kx, ky, positions, 0, dp);
    }
};