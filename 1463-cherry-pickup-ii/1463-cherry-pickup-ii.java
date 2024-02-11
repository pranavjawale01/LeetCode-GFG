class Solution {
    public int cherryPickup(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        int[][] prev = new int[n][n];
        prev[0][n - 1] = (n == 1) ? grid[0][0] : grid[0][0] + grid[0][n - 1];
        
        for (int row = 1; row < m; row++) {

            int[][] curr = new int[n][n];

            for (int c1 = 0; c1 <= Math.min(n - 1, row); c1++) {
                for (int c2 = Math.max(0, n - 1 - row); c2 < n; c2++) {

                    int prevMax = 0;
                    for (int column1 = Math.max(0, c1 - 1); column1 <= Math.min(n - 1, c1 + 1); column1++) {
                        for (int column2 = Math.max(0, c2 - 1); column2 <= Math.min(n - 1, c2 + 1); column2++) {
                            prevMax = Math.max(prevMax, prev[column1][column2]);
                        }
                    }

                    if (c1 == c2)
                        curr[c1][c2] = prevMax + grid[row][c1];
                    else
                        curr[c1][c2] = prevMax + grid[row][c1] + grid[row][c2];
                }
            }
            prev = curr;
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res = Math.max(res, prev[i][j]);
            }
        }
        return res;
    }
}

// class Solution {
//     public int cherryPickup(int[][] grid) {
//         int m = grid.length;
//         int n = grid[0].length;
        
//         int[][][] t = new int[71][71][71];
        
//         t[0][0][n - 1] = (n == 1) ? grid[0][0] : grid[0][0] + grid[0][n - 1]; 
        
//         for (int row = 1; row < m; row++) {
//             for (int c1 = 0; c1 <= Math.min(n - 1, row); c1++) {
//                 for (int c2 = Math.max(0, n - 1 - row); c2 < n; c2++) {
//                     int prevMax = 0;
//                     for (int column1 = Math.max(0, c1 - 1); column1 <= Math.min(n - 1, c1 + 1); column1++) {
//                         for (int column2 = Math.max(0, c2 - 1); column2 <= Math.min(n - 1, c2 + 1); column2++) {
//                             prevMax = Math.max(prevMax, t[row - 1][column1][column2]);
//                         }
//                     }
                    
//                     if (c1 == c2)
//                         t[row][c1][c2] = prevMax + grid[row][c1];
//                     else
//                         t[row][c1][c2] = prevMax + grid[row][c1] + grid[row][c2];
//                 }
//             }
//         }
        
//         int res = 0;
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 res = Math.max(res, t[m - 1][i][j]);    
//             }
//         }
//         return res;
//     }
// }


// // public class Solution {
// //     int m, n;
// //     int[][][] t;
// //     int[] colDir = {-1, 0, 1};
    
// //     boolean isSafe(int i) {
// //         return i >= 0 && i < n;
// //     }
    
// //     int solve(int[][] grid, int row, int c1, int c2) {
// //         if (row >= m)
// //             return 0;
        
// //         if (t[row][c1][c2] != -1) {
// //             return t[row][c1][c2];
// //         }
        
// //         int count = grid[row][c1];
// //         if (c1 != c2) {
// //             count += grid[row][c2];
// //         }
        
// //         int ans = 0;
// //         for(int x : colDir) {
// //             for(int y : colDir) {
// //                 int c1_ = x + c1;
// //                 int c2_ = y + c2;
// //                 if(isSafe(c1_) && isSafe(c2_)) {
// //                     ans = Math.max(ans, solve(grid, row+1, c1_, c2_));
// //                 }
// //             }
// //         }
        
// //         return t[row][c1][c2] = count + ans;
// //     }
    
// //     public int cherryPickup(int[][] grid) {
// //         m = grid.length;
// //         n = grid[0].length;
// //         t = new int[m][n][n];
// //         for(int[][] arr : t) {
// //             for(int[] row : arr) {
// //                 Arrays.fill(row, -1);
// //             }
// //         }
// //         return solve(grid, 0, 0, n-1);
// //     }
// // }