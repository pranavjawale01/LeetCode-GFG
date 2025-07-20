class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int row = points.size(), col = points[0].size();
        vector<long long> prevRow(points[0].begin(), points[0].end());

        for (int i = 1; i < row; ++i) {
            vector<long long> leftMax(col), rightMax(col);

            leftMax[0] = prevRow[0];
            for (int j = 1; j < col; ++j) {
                leftMax[j] = max(leftMax[j-1] - 1, prevRow[j]);
            }

            rightMax[col-1] = prevRow[col-1];
            for (int j = col-2; j >= 0; --j) {
                rightMax[j] = max(rightMax[j+1] - 1, prevRow[j]);
            }

            for (int j = 0; j < col; ++j) {
                prevRow[j] = points[i][j] + max(leftMax[j], rightMax[j]);
            }
        }

        return *max_element(prevRow.begin(), prevRow.end());
    }
};















// TLE
// class Solution {
// public:
//     vector<vector<long long>> dp;
//     int row, col;
    
//     long long solve(vector<vector<int>>& points, int i, int prev) {
//         if (i >= row) {
//             return 0;
//         }
//         if (dp[i][prev + 1] != -1) {
//             return dp[i][prev + 1];
//         }
//         long long maxEl = LLONG_MIN;
//         for (int k = 0; k < col; k++) {
//             long long score = points[i][k] + solve(points, i + 1, k);
//             if (prev != -1) {
//                 score -= abs(prev - k);
//             }
//             maxEl = max(maxEl, score);
//         }        
//         return dp[i][prev + 1] = maxEl;
//     }
    
//     long long maxPoints(vector<vector<int>>& points) {
//         row = points.size();
//         col = points[0].size();
//         dp = vector<vector<long long>>(row, vector<long long>(col + 1, -1));        
//         return solve(points, 0, -1);
//     }
// };