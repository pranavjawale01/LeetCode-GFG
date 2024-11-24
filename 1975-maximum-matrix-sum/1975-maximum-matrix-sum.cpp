class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        long long sum = 0;
        int neg = 0;
        int minEl = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum += abs(matrix[i][j]);
                neg += matrix[i][j] < 0 ? 1 : 0;
                minEl = min(minEl, abs(matrix[i][j]));
            }
        }
        if (neg % 2 == 0) {
            return sum;
        }
        return sum - 2 * minEl;
    }
};