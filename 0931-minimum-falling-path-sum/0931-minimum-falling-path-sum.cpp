class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        
        for (int i = 1; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int a = INT_MAX, b = INT_MAX;
                if (j - 1 >= 0) {
                    a = matrix[i-1][j-1];
                }
                if (j + 1 < row) {
                    b = matrix[i-1][j+1];
                }
                matrix[i][j] += min({matrix[i-1][j], a, b});
            }
        }
        
        int result = INT_MAX;
        
        for (int i = 0; i < col; i++) {
            result = min(result, matrix[row - 1][i]);
        }
        return result;
    }
};

// class Solution {
// public:
//     int n;
//     int result[101][101];
    
//     int minPath(vector<vector<int>>& matrix, int row, int col) {
//         if (row == n - 1) {
//             return matrix[row][col];
//         }
        
//         if (result[row][col] != -1) {
//             return result[row][col];
//         }
        
//         int sum = matrix[row][col];
//         int minSum = INT_MAX;

//         for (int shift = -1; shift <= 1; shift++) {
//              if (row + 1 < n && col + shift < n && col + shift >= 0) {
//                  minSum = min(minSum, sum minPath(matrix, row + 1, col + shift));
//              }
//         }
        
//         // if (row + 1 < n && col - 1 >= 0)
//         //     minSum = min(minSum, sum + minPath(matrix, row+1, col-1));
//         // if (row + 1 < n)
//         //     minSum = min(minSum, sum + minPath(matrix, row+1, col));
//         // if (row + 1 < n && col + 1 < n)
//         //     minSum = min(minSum, sum + minPath(matrix, row+1, col+1));        
        
//         if (row + 1 < n)
//             return result[row][col] = minSum;
//         else
//             return result[row][col] = sum;
//     }
    
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int minCost = INT_MAX;
//         n = matrix.size();
//         int row = 0;
//         memset(result, -1, sizeof(result));
        
//         for (int col = 0; col < n; col++) {
//             minCost = min(minCost, minPath(matrix, row, col));
//         }
        
//         return minCost;
//     }
// };