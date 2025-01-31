class Solution {
public:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int n;

    int dfs(vector<vector<int>>& grid, int i, int j, int id) {
        if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] != 1) {
            return 0;
        }
        grid[i][j] = id;
        int count = 1;
        for (auto &d : dirs) {
            int x = d[0] + i;
            int y = d[1] + j;
            count += dfs(grid, x, y, id);
        }
        return count;
    }

    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        int maxArea = 0;
        unordered_map<int, int> mp;
        int id = 2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int size = dfs(grid, i, j, id);
                    maxArea = max(maxArea, size);
                    mp[id] = size;
                    id++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> st;
                    for (auto &d : dirs) {
                        int x = i + d[0];
                        int y = j + d[1];
                        if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] != 0) {
                            st.insert(grid[x][y]);
                        }
                    }
                    int sum = 1;
                    for (auto &x : st) sum += mp[x];
                    maxArea = max(maxArea, sum);
                }
            }
        }
        return maxArea == 0 ? n * n : maxArea;
    }
};

// TLE 69 / 75
// class Solution {
// public:
//     vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
//     int n;

//     int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>> &vis) {
//         if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == 0 || vis[i][j]) {
//             return 0;
//         }
//         vis[i][j] = true;
//         int count = 1;
//         for (auto &d : dirs) {
//             int x = d[0] + i;
//             int y = d[1] + j;
//             count += dfs(grid, x, y, vis);
//         }
//         return count;
//     }

//     int largestIsland(vector<vector<int>>& grid) {
//         n = grid.size();
//         int maxArea = 0;
//         vector<vector<bool>> vs(n, vector<bool>(n, false));
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (grid[i][j] == 1 && !vs[i][j]) {
//                     maxArea = max(maxArea, dfs(grid, i, j, vs));
//                 }
//             }
//         }
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (grid[i][j] == 0) {
//                     grid[i][j] = 1;
//                     vector<vector<bool>> vis(n, vector<bool>(n, false));
//                     int largest = dfs(grid, i, j, vis);
//                     grid[i][j] = 0;
//                     maxArea = max(maxArea, largest);
//                 }
//             }
//         }
//         return maxArea == 0 ? n * n : maxArea;
//     }
// };


// // TLE 66 / 75
// // class Solution {
// // public:
// //     vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
// //     int n;

// //     int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>> &vis) {
// //         if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == 0 || vis[i][j]) {
// //             return 0;
// //         }
// //         vis[i][j] = true;
// //         int count = 1;
// //         for (auto &d : dirs) {
// //             int x = d[0] + i;
// //             int y = d[1] + j;
// //             count += dfs(grid, x, y, vis);
// //         }
// //         return count;
// //     }

// //     int largestIsland(vector<vector<int>>& grid) {
// //         n = grid.size();
// //         int maxArea = 0;
// //         for (int i = 0; i < n; i++) {
// //             for (int j = 0; j < n; j++) {
// //                 if (grid[i][j] == 0) {
// //                     grid[i][j] = 1;
// //                     int largest = 0;
// //                     vector<vector<bool>> vis(n, vector<bool>(n, false));
// //                     for (int x = 0; x < n; x++) {
// //                         for (int y = 0; y < n; y++) {
// //                             if (grid[x][y] == 1 && !vis[x][y]) {
// //                                 largest = max(largest, dfs(grid, x, y, vis));
// //                             }
// //                         }
// //                     }
// //                     grid[i][j] = 0;
// //                     maxArea = max(maxArea, largest);
// //                 }
// //             }
// //         }
// //         return maxArea == 0 ? n * n : maxArea;
// //     }
// // };