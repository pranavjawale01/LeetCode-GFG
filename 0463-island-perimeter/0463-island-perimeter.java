class Solution {
    public int islandPerimeter(int[][] grid) {
        int row = grid.length;
        int col = grid[0].length;
        int peri = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    if (j+1 == col || grid[i][j+1] == 0) {
                        peri++;
                    }
                    if (j-1 < 0 || grid[i][j-1] == 0) {
                        peri++;
                    }
                    if (i-1 < 0 || grid[i-1][j] == 0) {
                        peri++;
                    }
                    if (i+1 == row || grid[i+1][j] == 0) {
                        peri++;
                    }
                }
            }
        }
        return peri;
    }
}

// class Solution {
//     public int bfs(int[][] grid, int i, int j, int row, int col) {
//         int peri = 0;
//         Queue<int[]> q = new LinkedList<>();
//         q.offer(new int[]{i, j});
//         grid[i][j] = -1;
//         int[][] dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
//         while (!q.isEmpty()) {
//             int[] it = q.poll();
//             for (int[] d : dir) {
//                 int i_ = it[0] + d[0];
//                 int j_ = it[1] + d[1];
//                 if (i_ < 0 || j_ < 0 || i_ >= row || j_ >= col || grid[i_][j_] == 0) {
//                     peri++;
//                 } else if (grid[i_][j_] == -1) {
//                     continue;
//                 } else {
//                     q.offer(new int[]{i_, j_});
//                     grid[i_][j_] = -1;
//                 }
//             }
//         }
//         return peri;
//     }
    
//     public int islandPerimeter(int[][] grid) {
//         int row = grid.length;
//         int col = grid[0].length;
//         for (int i = 0; i < row; i++) {
//             for (int j = 0; j < col; j++) {
//                 if (grid[i][j] == 1) {
//                     return bfs(grid, i, j, row, col);
//                 }
//             }
//         }
//         return 0;
//     }
// }

// class Solution {
//     public void solve(int[][] grid, int i, int j, int row, int col, int[] peri) {
//         if (i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == 0) {
//             peri[0]++;
//             return;
//         }
//         if (grid[i][j] == -1) {
//             return;
//         }
//         grid[i][j] = -1;
//         solve(grid, i+1, j, row, col, peri);
//         solve(grid, i-1, j, row, col, peri);
//         solve(grid, i, j+1, row, col, peri);
//         solve(grid, i, j-1, row, col, peri);
//     }
//     public int islandPerimeter(int[][] grid) {
//         int row = grid.length;
//         int col = grid[0].length;
//         int[] peri = new int[1];
//         peri[0] = 0;
//         for (int i = 0; i < row; i++) {
//             for (int j = 0; j < col; j++) {
//                 if (grid[i][j] == 1) {
//                     solve(grid, i, j, row, col, peri);
//                     return peri[0];
//                 }
//             }
//         }
//         return 0;
//     }
// }