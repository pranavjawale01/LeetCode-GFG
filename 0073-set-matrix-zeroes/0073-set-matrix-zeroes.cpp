class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<int> zeroRow(row, 0), zeroCol(col, 0);

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == 0) {
                    zeroRow[i] = 1;
                    zeroCol[j] = 1;
                }
            }
        }

        for (int i = 0; i < row; i++) {
            if (zeroRow[i] == 1) {
                fill(matrix[i].begin(), matrix[i].end(), 0);
            }
        }

        for (int j = 0; j < col; j++) {
            if (zeroCol[j] == 1) {
                for (int i = 0; i < row; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};