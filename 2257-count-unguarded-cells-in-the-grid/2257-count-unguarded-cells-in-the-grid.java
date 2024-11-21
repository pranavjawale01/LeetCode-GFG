class Solution {
    public void dfs(int[][] grid, int row, int col, int rows, int cols, int direction) {
        if (row < 0 || col < 0 || row >= rows || col >= cols || grid[row][col] == 1 || grid[row][col] == 2) {
            return;
        }
        grid[row][col] = 3;
        if (direction == 1) {
            dfs(grid, row - 1, col, rows, cols, direction);
        } else if (direction == 2) {
            dfs(grid, row + 1, col, rows, cols, direction);
        } else if (direction == 3) {
            dfs(grid, row, col - 1, rows, cols, direction);
        } else {
            dfs(grid, row, col + 1, rows, cols, direction);
        }
    }

    public int countUnguarded(int rows, int cols, int[][] guards, int[][] walls) {
        int[][] grid = new int[rows][cols];
        for (int[] guard : guards) {
            grid[guard[0]][guard[1]] = 2;
        }
        for (int[] wall : walls) {
            grid[wall[0]][wall[1]] = 1;
        }
        for (int[] guard : guards) {
            int guardRow = guard[0];
            int guardCol = guard[1];
            dfs(grid, guardRow - 1, guardCol, rows, cols, 1);
            dfs(grid, guardRow + 1, guardCol, rows, cols, 2);
            dfs(grid, guardRow, guardCol - 1, rows, cols, 3);
            dfs(grid, guardRow, guardCol + 1, rows, cols, 4);
        }
        int unguardedCount = 0;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == 0) {
                    unguardedCount++;
                }
            }
        }
        return unguardedCount;
    }
}




// class Solution {
//     public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {
//         int[][] grid = new int[m][n];
//         int[][] directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

//         for (int[] wall : walls) {
//             grid[wall[0]][wall[1]] = 1;
//         }

//         for (int[] guard : guards) {
//             grid[guard[0]][guard[1]] = 2;
//         }

//         for (int[] guard : guards) {
//             int x = guard[0];
//             int y = guard[1];

//             for (int[] dir : directions) {
//                 int nx = x + dir[0];
//                 int ny = y + dir[1];

//                 while (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] != 1 && grid[nx][ny] != 2) {
//                     if (grid[nx][ny] == 0) {
//                         grid[nx][ny] = 3;
//                     }
//                     nx += dir[0];
//                     ny += dir[1];
//                 }
//             }
//         }

//         int count = 0;
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (grid[i][j] == 0) {
//                     count++;
//                 }
//             }
//         }

//         return count;
//     }
// }