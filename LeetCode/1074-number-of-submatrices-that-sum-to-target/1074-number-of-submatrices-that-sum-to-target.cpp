class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();

        for (int i = 0; i < row; i++) {
            for (int j = 1; j < col; j++) {
                matrix[i][j] += matrix[i][j - 1];
            }
        }

        int result = 0;

        for (int i = 0; i < col; i++) {
            for (int j = i; j < col; j++) {
                unordered_map<int, int> mp;
                mp[0] = 1;
                int cumSum = 0;

                for (int l = 0; l < row; l++) {
                    cumSum += matrix[l][j] - (i > 0 ? matrix[l][i - 1] : 0);
                    if (mp.find(cumSum - target) != mp.end()) {
                        result += mp[cumSum - target];
                    }
                    mp[cumSum]++;
                }
            }
        }
        return result;
    }
};