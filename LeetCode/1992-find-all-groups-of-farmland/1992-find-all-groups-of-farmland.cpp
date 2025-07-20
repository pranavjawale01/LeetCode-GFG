class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int row = land.size();
        int col = land[0].size();
        vector<vector<int>> ans;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (land[i][j] == 1) {
                    int i_max = i;
                    while (i_max < row && land[i_max][j] == 1) {
                        i_max++;
                    }
                    int j_max = j;
                    while (j_max < col && land[i][j_max] == 1) {
                        j_max++;
                    }
                    i_max = (i_max > 0) ? i_max - 1 : i_max;
                    j_max = (j_max > 0) ? j_max - 1 : j_max;
                    ans.push_back({i, j, i_max, j_max});
                    for (int k = i; k <= i_max; k++) {
                        for (int l = j; l <= j_max; l++) {
                            land[k][l] = 0;
                        }
                    }
                }
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     void bfs(vector<vector<int>>& land, int i, int j, int row, int col, int& max_i, int& max_j) {
//         queue<pair<int, int>> q;
//         q.push({i, j});
//         vector<vector<int>> direction{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
//         while (!q.empty()) {
//             pair<int, int> p = q.front();
//             q.pop();
//             max_i = max(max_i, p.first);
//             max_j = max(max_j, p.second);
//             for (auto& dir : direction) {
//                 int i_ = p.first + dir[0];
//                 int j_ = p.second + dir[1];
//                 if (i_ >= 0 && i_ < row && j_ >= 0 && j_ < col && land[i_][j_] == 1) {
//                     land[i_][j_] = 0;
//                     q.push({i_, j_});
//                 }
//             }
//         }
//     }

//     vector<vector<int>> findFarmland(vector<vector<int>>& land) {
//         int row = land.size();
//         int col = land[0].size();
//         vector<vector<int>> ans;
//         for (int i = 0; i < row; i++) {
//             for (int j = 0; j < col; j++) {
//                 if (land[i][j] == 1) {
//                     int max_i = i, max_j = j;
//                     bfs(land, i, j, row, col, max_i, max_j);
//                     ans.push_back({i, j, max_i, max_j});
//                 }
//             }
//         }
//         return ans;
//     }
// };


// class Solution {
// public:
//     void dfs(vector<vector<int>>& land, int i, int j, int row, int col, int &max_i, int &max_j) {
//         if (i < 0 || j < 0 || i >= row || j >= col || land[i][j] == 0) {
//             max_i = max(i-1, max_i);
//             max_j = max(j-1, max_j);
//             return;
//         }
//         land[i][j] = 0;
//         max_i = max(i, max_i);
//         max_j = max(j, max_j);
//         dfs(land, i+1, j, row, col, max_i, max_j);
//         dfs(land, i-1, j, row, col, max_i, max_j);
//         dfs(land, i, j+1, row, col, max_i, max_j);
//         dfs(land, i, j-1, row, col, max_i, max_j);
//     }
//     vector<vector<int>> findFarmland(vector<vector<int>>& land) {
//         int row = land.size();
//         int col = land[0].size();
//         vector<vector<int>> ans;
//         for (int i = 0; i < row; i++) {
//             for (int j = 0; j < col; j++) {
//                 if (land[i][j] == 1) {
//                     int max_i = i, max_j = j;
//                     dfs(land, i, j, row, col, max_i, max_j);
//                     ans.push_back({i, j, max_i, max_j});
//                 }
//             }
//         }
//         return ans;
//     }
// };