class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        vector<vector<char>> result(n, vector<char>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                result[i][j] = box[j][i];
            }
        }
        for(vector<char>& row : result) {
            reverse(begin(row), end(row));
        }
        for(int j = 0; j < m; j++) {
            int spaceBottomRow = n-1;
            for(int i = n-1; i >= 0; i--) {
                if(result[i][j] == '*') {
                    spaceBottomRow = i-1;
                    continue;
                }
                if(result[i][j] == '#') {
                    result[i][j] = '.';
                    result[spaceBottomRow][j] = '#';
                    spaceBottomRow--;
                }
            }
        }
        return result;
    }
};











// class Solution {
// public:
//     vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
//         int m = box.size(), n = box[0].size();
//         vector<vector<char>> ans(n, vector<char>(m));
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 ans[i][j] = box[j][i];
//             }
//         }
//         for (int i = 0; i < n; i++) {
//             reverse(ans[i].begin(), ans[i].end());
//         }
//         for (int j = 0; j < m; j++) {
//             for (int i = n - 1; i >= 0; i--) {
//                 if (ans[i][j] == '.') {
//                     int stoneRow = -1;
//                     for (int k = i - 1; k >= 0; k--) {
//                         if (ans[k][j] == '*') break;
//                         if (ans[k][j] == '#') {
//                             stoneRow = k;
//                             break;
//                         }
//                     }
//                     if (stoneRow != -1) {
//                         ans[i][j] = '#';
//                         ans[stoneRow][j] = '.';
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };