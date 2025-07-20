#include <vector>

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int count = 0;

        vector<int> rowSum(m, 0);
        vector<int> colSum(n, 0);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rowSum[i] += mat[i][j];
                colSum[j] += mat[i][j];
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1 && rowSum[i] == 1 && colSum[j] == 1) {
                    count++;
                }
            }
        }

        return count;
    }
};

// class Solution {
// public:
//     void check(vector<vector<int>>& mat, int i, int j, int& count) {
//         bool rowSpecial = true;
//         bool colSpecial = true;

//         for (int k = 0; k < mat.size(); k++) {
//             if (mat[i][k] == 1 && k != j) {
//                 rowSpecial = false;
//                 break;
//             }
//         }

//         for (int k = 0; k < mat[0].size(); k++) {
//             if (mat[k][j] == 1 && k != i) {
//                 colSpecial = false;
//                 break;
//             }
//         }

//         if (rowSpecial && colSpecial) {
//             count++;
//         }
//     }

//     int numSpecial(vector<vector<int>>& mat) {
//         int count = 0;
//         for (int i = 0; i < mat.size(); i++) {
//             for (int j = 0; j < mat[0].size(); j++) {
//                 if (mat[i][j] == 1) {
//                     check(mat, i, j, count);
//                 }
//             }
//         }
//         return count;
//     }
// };