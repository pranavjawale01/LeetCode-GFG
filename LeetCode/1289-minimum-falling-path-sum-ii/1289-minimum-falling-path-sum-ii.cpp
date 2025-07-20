class Solution {
public:    
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();

        int nextMin1Col = -1;
        int nextMin2Col = -1;
        
        int nextMin1Val = -1;
        int nextMin2Val = -1;
        
        for (int col = 0; col < n; col++) {

            if(nextMin1Col == -1 || grid[n - 1][col] <= nextMin1Val) {
                nextMin2Col = nextMin1Col;
                nextMin2Val = nextMin1Val;
                
                nextMin1Col = col;
                nextMin1Val = grid[n-1][col];
                
            } else if(nextMin2Col == -1 || grid[n - 1][col] <= nextMin2Val) {
                nextMin2Col = col;
                nextMin2Val = grid[n-1][col];
            }
        }

        for (int row = n - 2; row >= 0; row--) {
            
            int min1Col = -1;
            int min2Col = -1;
            
            int min1Val = -1;
            int min2Val = -1;
            
            for (int col = 0; col < n; col++) {
                
                int ans;
                if(col != nextMin1Col) {
                    ans = grid[row][col] + nextMin1Val;
                } else {
                    ans = grid[row][col] + nextMin2Val;
                }
                
                if(min1Col == -1 || ans <= min1Val) {
                    min2Col = min1Col;
                    min2Val = min1Val;
                    
                    min1Col = col;
                    min1Val = ans;
                } else if(min2Col == -1 || ans <= min2Val) {
                    min2Col = col;
                    min2Val = ans;
                }
            }
                            
            nextMin1Col = min1Col;
            nextMin1Val = min1Val;
            
            nextMin2Col = min2Col;
            nextMin2Val = min2Val;
                
        }

        return nextMin1Val;
    }
};




// class Solution {
// public:
//     int minFallingPathSum(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int dp[n+1][n+1];

//         int nextMinCol1 = -1, nextMinCol2 = -1;
        
//         for (int i = 0; i < n; i++) {
//             dp[n-1][i] = grid[n-1][i];  

//             if (nextMinCol1 == -1 || dp[n-1][i] <= dp[n-1][nextMinCol1]) {
//                 nextMinCol2 = nextMinCol1;
//                 nextMinCol1 = i;
//             } else if (nextMinCol2 == -1 || dp[n-1][i] <= dp[n-1][nextMinCol2]) {
//                 nextMinCol2 = i;
//             }
//         }

//         for (int row = n - 2; row >= 0; row--) {

//             int minCol1 = -1, minCol2 = -1;
            
//             for (int col = 0; col < n; col++) {
                
//                 if (col == nextMinCol1) {
//                     dp[row][col] = grid[row][col] + dp[row+1][nextMinCol2];
//                 } else {
//                     dp[row][col] = grid[row][col] + dp[row+1][nextMinCol1];
//                 }

//                 if (minCol1 == -1 || dp[row][col] <= dp[row][minCol1]) {
//                     minCol2 = minCol1;
//                     minCol1 = col;
//                 } else if (minCol2 == -1 || dp[row][col] <= dp[row][minCol2]) {
//                     minCol2 = col;
//                 }                
//             }
//             nextMinCol1 = minCol1;
//             nextMinCol2 = minCol2;
//         }
//         int ans = INT_MAX;
//         for (int i = 0; i < n; i++) {
//             ans = min(ans, dp[0][i]);
//         }
//         return ans;
//     }
// };



// class Solution {
// public:
//     int minFallingPathSum(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int dp[n+1][n+1];
//         for (int i = 0; i < n; i++) {
//             dp[n-1][i] = grid[n-1][i];
//         }
//         for (int row = n - 2; row >= 0; row--) {
//             for (int col = 0; col < n; col++) {
//                 int ans = INT_MAX;
//                 for (int nextCol = 0; nextCol < n; nextCol++) {
//                     if (nextCol != col) {
//                         ans = min(ans, dp[row+1][nextCol]);
//                     }
//                 }
//                 dp[row][col] = ans + grid[row][col];
//             }
//         }
//         int ans = INT_MAX;
//         for (int i = 0; i < n; i++) {
//             ans = min(ans, dp[0][i]);
//         }
//         return ans;
//     }
// };




// class Solution {
// public:
//     int dp[201][201];
//     int solve(vector<vector<int>>& grid, int n, int level, int col) {
//         if (level == n - 1) {
//             return dp[level][col] = grid[level][col];
//         }
//         if (dp[level][col] != -1) {
//             return dp[level][col];
//         }
//         int ans = INT_MAX;
//         for (int j = 0; j < n; j++) {
//             if (col == j) {
//                 continue;
//             }
//             ans = min(ans, grid[level][col] + solve(grid, n, level+1, j));
//         }
//         return dp[level][col] = ans;
//     }
//     int minFallingPathSum(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int ans = INT_MAX;
//         memset(dp, -1, sizeof(dp));
//         for (int j = 0; j < n; j++) {
//             ans = min(ans, solve(grid, n, 0, j));
//         }
//         return ans;
//     }
// };