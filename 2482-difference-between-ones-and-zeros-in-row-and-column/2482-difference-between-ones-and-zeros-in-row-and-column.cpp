class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<int> zeroRow(rows, 0);
        vector<int> oneRow(rows, 0);
        vector<int> zeroCol(cols, 0);
        vector<int> oneCol(cols, 0);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) {
                    zeroRow[i]++;
                    zeroCol[j]++;
                } else if (grid[i][j] == 1) {
                    oneRow[i]++;
                    oneCol[j]++;
                }
            }
        }

        vector<vector<int>> matrix(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = oneRow[i] + oneCol[j] - zeroRow[i] - zeroCol[j];
            }
        }

        return matrix;
    }
};