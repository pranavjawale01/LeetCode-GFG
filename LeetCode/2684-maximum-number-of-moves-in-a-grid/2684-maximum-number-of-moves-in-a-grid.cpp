class Solution {
public:
    int n, m;
    vector<vector<int>> memo;

    int solve(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= m) {
            return 0;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        int up = 0, down = 0, fwd = 0; 
        if (i - 1 >= 0 && j + 1 < m && grid[i][j] < grid[i-1][j+1]) {
            up = 1 + solve(grid, i-1, j+1);
        }
        if (j + 1 < m && grid[i][j] < grid[i][j+1]) {
            fwd = 1 + solve(grid, i, j+1);
        }
        if (i + 1 < n && j + 1 < m && grid[i][j] < grid[i+1][j+1]) {
            down = 1 + solve(grid, i+1, j+1);
        }
        return memo[i][j] = max({up, fwd, down});
    }

    int maxMoves(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        memo = vector<vector<int>>(n, vector<int>(m, -1));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, solve(grid, i, 0));
        }
        return ans;
    }
};