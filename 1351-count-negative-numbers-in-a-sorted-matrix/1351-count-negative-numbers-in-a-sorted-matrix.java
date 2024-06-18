class Solution {
    public int binarySearch(int[] mat, int n) {
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mat[mid] < 0) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return n - low;
    }
    public int countNegatives(int[][] grid) {
        int row = grid.length, col = grid[0].length;
        int totalCount = 0;
        for (int i = 0; i < row; i++) {
            totalCount += binarySearch(grid[i], col);
        }
        return totalCount;
    }
}