class Solution {
public:
    int binarySearch(vector<int> &mat, int n) {
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
    
    int countNegatives(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int totalCount = 0;
        for (int i = 0; i < row; i++) {
            totalCount += binarySearch(grid[i], col);
        }
        return totalCount;
    }
};