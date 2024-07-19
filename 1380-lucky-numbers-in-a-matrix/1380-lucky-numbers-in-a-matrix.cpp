class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        int rMinMax = INT_MIN;
        for (int i = 0; i < row; i++) {
            int rMin = INT_MAX;
            for (int j = 0; j < col; j++) {
                rMin = min(rMin, matrix[i][j]);
            }
            rMinMax = max(rMinMax, rMin);
        }
        int cMaxMin = INT_MAX;
        for (int j = 0; j < col; j++) {
            int cMax = INT_MIN;
            for (int i = 0; i < row; i++) {
                cMax = max(cMax, matrix[i][j]);
            }
            cMaxMin = min(cMaxMin, cMax);
        }
        if (cMaxMin == rMinMax) {
            return {rMinMax};
        }
        return {};
    }
};









// class Solution {
// public:
//     vector<int> luckyNumbers (vector<vector<int>>& matrix) {
//         int row = matrix.size(), col = matrix[0].size();
//         vector<int> minRow(row, INT_MAX);
//         vector<int> maxCol(col, INT_MIN);
//         for (int i = 0; i < row; i++) {
//             minRow[i] = *min_element(matrix[i].begin(), matrix[i].end());
//         }
//         for (int i = 0; i < col; i++) {
//             for (int j = 0; j < row; j++) {
//                 maxCol[i] = max(matrix[j][i], maxCol[i]);
//             }
//         }
//         vector<int> ans;
//         for (int i = 0; i < row; i++) {
//             for (int j = 0; j < col; j++) {
//                 if (minRow[i] == maxCol[j]) {
//                     ans.push_back(minRow[i]);
//                 }
//             }
//         }
//         return ans;
//     }
// };