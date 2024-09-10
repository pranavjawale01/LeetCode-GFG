class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix.length == 0 || matrix[0].length == 0) return false;
        
        int n = matrix.length;
        int m = matrix[0].length;
        
        int row = 0;
        while (row < n && target > matrix[row][m - 1]) {
            row++;
        }
        
        if (row == n) return false;
        
        int low = 0, high = m - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (matrix[row][mid] == target) {
                return true;
            } else if (matrix[row][mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return false;
    }
}