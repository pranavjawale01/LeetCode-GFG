class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int low = 0, high = n * m - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int row = mid / m, col = mid % m;
            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] < target) low = mid + 1;
            else high = mid - 1;
        }
    return false;
    }
};



// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         if (matrix.empty() || matrix[0].empty()) return false;

//         int n = matrix.size();
//         int m = matrix[0].size();
        
//         int row = 0;
//         while (row < n && target > matrix[row][m - 1]) {
//             row++;
//         }
        
//         if (row == n) return false;

//         int low = 0, high = m - 1;
//         while (low <= high) {
//             int mid = low + (high - low) / 2;
//             if (matrix[row][mid] == target) {
//                 return true;
//             } else if (matrix[row][mid] < target) {
//                 low = mid + 1;
//             } else {
//                 high = mid - 1;
//             }
//         }
        
//         return false;
//     }
// };