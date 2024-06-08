class Solution {
public:
    int findNearZero(vector<vector<int>> mat, int i, int j) {
        int level = 0;
        queue<pair<int, int>> q;
        q.push({i, j});
        
        mat[i][j] = -1;

        while (!q.empty()) {
            int n = q.size();
            for (int k = 0; k < n; k++) {
                pair<int, int> temp = q.front();
                q.pop();
                int x = temp.first;
                int y = temp.second;

                if (mat[x][y] == 0) {
                    return level;
                }

                if (x - 1 >= 0 && mat[x - 1][y] != -1) {
                    q.push({x - 1, y});
                    if (mat[x - 1][y] == 1) mat[x - 1][y] = -1;
                }
                if (y - 1 >= 0 && mat[x][y - 1] != -1) {
                    q.push({x, y - 1});
                    if (mat[x][y - 1] == 1) mat[x][y - 1] = -1;
                }
                if (x + 1 < mat.size() && mat[x + 1][y] != -1) {
                    q.push({x + 1, y});
                    if (mat[x + 1][y] == 1) mat[x + 1][y] = -1;
                }
                if (y + 1 < mat[0].size() && mat[x][y + 1] != -1) {
                    q.push({x, y + 1});
                    if (mat[x][y + 1] == 1) mat[x][y + 1] = -1;
                }
            }
            level++;
        }
        return level;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size();
        vector<vector<int>> ans(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (mat[i][j] == 1) {
                    ans[i][j] = findNearZero(mat, i, j);
                }
            }
        }
        return ans;
    }
};