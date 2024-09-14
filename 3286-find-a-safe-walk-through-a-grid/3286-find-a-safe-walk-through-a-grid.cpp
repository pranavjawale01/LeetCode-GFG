class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, health - grid[0][0]});
        dp[0][0] = health - grid[0][0];
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        while (!q.empty()) {
            auto top = q.front();
            int x = top.first.first;
            int y = top.first.second;
            int val = top.second;
            q.pop();
            
            if (x == n - 1 && y == m - 1) {
                if (val > 0) {
                    return true;
                }
            }
            
            for (auto &dir : dirs) {
                int newX = x + dir[0];
                int newY = y + dir[1];
                
                if (newX >= 0 && newY >= 0 && newX < n && newY < m) {
                    int newVal = val - grid[newX][newY];
                    if (newVal > 0 && newVal > dp[newX][newY]) {
                        q.push({{newX, newY}, newVal});
                        dp[newX][newY] = newVal;
                    }
                }
            }
        }
        return false;
    }
};








// class Solution {
// public:
//     vector<vector<bool>> dp;
    
//     bool pranavjawale01(int i, int j, int m, int n, vector<vector<int>>& grid, int health) {
//         if (i == m - 1 && j == n - 1) {
//             return health >= 1;
//         }
//         if (i < 0 || j < 0 || i >= m || j >= n || health <= 0) {
//             return false;
//         }
//         if (dp[i][j]) {
//             return dp[i][j];
//         }
//         int poison = (grid[i][j] == 1) ? 1 : 0;
//         bool a = pranavjawale01(i + 1, j, m, n, grid, health - poison);
//         bool b = pranavjawale01(i - 1, j, m, n, grid, health - poison);
//         bool c = pranavjawale01(i, j + 1, m, n, grid, health - poison);
//         bool d = pranavjawale01(i, j - 1, m, n, grid, health - poison);
//         return dp[i][j] = a || b || c || d;
//     }
    
//     bool findSafeWalk(vector<vector<int>>& grid, int health) {
//         int row = grid.size();
//         int col = grid[0].size();
//         dp.resize(row, vector<bool>(col, false));
//         return pranavjawale01(0, 0, row, col, grid, health);
//     }
// };