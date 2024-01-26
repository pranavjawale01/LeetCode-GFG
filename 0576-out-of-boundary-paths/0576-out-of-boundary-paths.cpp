class Solution {
public:
    int MOD = 1e9+7;
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {

        vector<vector<int>> t(50, vector<int>(50));
        t[startRow][startColumn] = 1;
        int result = 0;

        for (int k = 1; k <= maxMove; ++k) {
            vector<vector<int>> temp(50, vector<int>(50));
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    
                    for(auto &dir : directions) {
                        int x = i + dir[0];
                        int y = j + dir[1];
                        if (x < 0 || x >= m || y < 0 || y >= n) {
                            result = (result + t[i][j]) % MOD;
                        }
                        else {
                            temp[x][y] = (temp[x][y] + t[i][j]) % MOD;
                        }
                    }
                }
            }
            t = temp;
        }

        return result;

    }
};