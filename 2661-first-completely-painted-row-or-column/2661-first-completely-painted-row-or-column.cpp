class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, pair<int, int>> mp;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mp[mat[i][j]] = {i, j};
            }
        }
        vector<int> rowCount(m, 0);
        vector<int> colCount(n, 0);
        for (int i = 0; i < arr.size(); i++) {
            int val = arr[i];
            auto [row, col] = mp[val];
            rowCount[row]++;
            colCount[col]++;
            if (rowCount[row] == n || colCount[col] == m) {
                return i;
            }
        }
        return -1;
    }
};








// TLE
// class Solution {
// public:
//     bool checkRow(vector<vector<int>> &mat, int row) {
//         for (int i = 0; i < mat[0].size(); i++) {
//             if (mat[row][i] > 0) return false;
//         }
//         return true;
//     }
//     bool checkCol(vector<vector<int>> &mat, int col) {
//         for (int i = 0; i < mat.size(); i++) {
//             if (mat[i][col] > 0) return false;
//         }
//         return true;
//     }
//     int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
//         int m = mat.size(), n = mat[0].size();
//         unordered_map<int, pair<int, int>> mp;
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 mp[mat[i][j]] = {i, j};
//             }
//         }
//         for (int i = 0; i < arr.size(); i++) {
//             int val = arr[i];
//             auto [row, col] = mp[val];
//             mat[row][col] *= -1;
//             if (checkRow(mat, row) || checkCol(mat, col)) {
//                 return i;
//             }
//         }
//         return -1;
//     }
// };