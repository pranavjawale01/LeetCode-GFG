class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long firstRowSum = accumulate(grid[0].begin(), grid[0].end(), 0LL);
        long long secondRowSum = 0, minRob2Sum = LLONG_MAX;

        for (int i = 0; i < n; ++i) {
            firstRowSum -= grid[0][i];
            minRob2Sum = min(minRob2Sum, max(firstRowSum, secondRowSum));
            secondRowSum += grid[1][i];
        }

        return minRob2Sum;
    }
};