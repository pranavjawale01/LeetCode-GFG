class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        for (auto &curr : matrix) {
            vector<int> inv(n);
            for (int i = 0; i < n; i++) {
                inv[i] = curr[i] == 0 ? 1 : 0;
            }
            int count = 0;
            for (auto &row : matrix) {
                if (row == curr || row == inv) count++;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};