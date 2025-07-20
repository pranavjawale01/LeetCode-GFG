class Solution {
public:
    bool isMagicSquare(vector<vector<int>>& grid, int r, int c) {
        set<int> st;
        int sum = 15;
        
        for (int i = r; i < r+3; i++) {
            for (int j = c; j < c+3; j++) {
                if (grid[i][j] < 1 || grid[i][j] > 9 || st.find(grid[i][j]) != st.end()) {
                    return false;
                }
                st.insert(grid[i][j]);
            }
        }
        
        if (grid[r][c] + grid[r][c+1] + grid[r][c+2] != sum) return false;
        if (grid[r+1][c] + grid[r+1][c+1] + grid[r+1][c+2] != sum) return false;
        if (grid[r+2][c] + grid[r+2][c+1] + grid[r+2][c+2] != sum) return false;
        
        if (grid[r][c] + grid[r+1][c] + grid[r+2][c] != sum) return false;
        if (grid[r][c+1] + grid[r+1][c+1] + grid[r+2][c+1] != sum) return false;
        if (grid[r][c+2] + grid[r+1][c+2] + grid[r+2][c+2] != sum) return false;
        
        if (grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2] != sum) return false;
        if (grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c] != sum) return false;
        
        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        if (row < 3 || col < 3) {
            return 0;
        }
        int count = 0;
        for (int i = 0; i <= row - 3; i++) {
            for (int j = 0; j <= col - 3; j++) {
                if (isMagicSquare(grid, i, j)) {
                    count++;
                }
            }
        }
        return count;
    }
};