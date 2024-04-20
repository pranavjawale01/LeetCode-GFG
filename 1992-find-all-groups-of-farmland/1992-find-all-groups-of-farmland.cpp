class Solution {
public:
    void dfs(vector<vector<int>>& land, int i, int j, int row, int col, int &max_i, int &max_j) {
        if (i < 0 || j < 0 || i >= row || j >= col || land[i][j] == 0) {
            max_i = max(i-1, max_i);
            max_j = max(j-1, max_j);
            return;
        }
        land[i][j] = 0;
        max_i = max(i, max_i);
        max_j = max(j, max_j);
        dfs(land, i+1, j, row, col, max_i, max_j);
        dfs(land, i-1, j, row, col, max_i, max_j);
        dfs(land, i, j+1, row, col, max_i, max_j);
        dfs(land, i, j-1, row, col, max_i, max_j);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int row = land.size();
        int col = land[0].size();
        vector<vector<int>> ans;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (land[i][j] == 1) {
                    int max_i = i, max_j = j;
                    dfs(land, i, j, row, col, max_i, max_j);
                    ans.push_back({i, j, max_i, max_j});
                }
            }
        }
        return ans;
    }
};