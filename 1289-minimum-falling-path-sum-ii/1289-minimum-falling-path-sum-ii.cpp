class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        long long ans = 0;
        int prevj = -1;
        for (int i = 0; i < n; i++) {
            int temp = INT_MAX;
            for (int j = 0; j < n; j++) {
                if (j == prevj) {
                    continue;
                }
                if (temp > grid[i][j]) {
                    temp = grid[i][j];
                    prevj = j;
                }
            }
            ans += temp;
        }
        return ans;
    }
};