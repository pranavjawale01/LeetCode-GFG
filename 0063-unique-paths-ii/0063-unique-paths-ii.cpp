class Solution {
public:
    int solve(vector<vector<int>>& arr, int i, int j) {
        if (i < 0 || j < 0 || i >= arr.size() || j >= arr[0].size() || arr[i][j]) {
            return 0;
        }
        if (i == arr.size() - 1 && j == arr[0].size() - 1) {
            return 1;
        }
        return solve(arr, i+1, j) + solve(arr, i, j+1);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        return solve(obstacleGrid, 0, 0);
    }
};