class DSU {
    vector<int> parent;
    vector<int> size;
public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }    

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx == rooty) {
            return;
        }
        if (size[rootx] > size[rooty]) {
            parent[rooty] = rootx;
            size[rootx] += size[rooty];
        } else {
            parent[rootx] = rooty;
            size[rooty] += size[rootx];
        }
    }

    int getSize(int x) {
        return size[find(x)];
    }
};

class Solution {
public:
    vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int totalCells = n * n;
        DSU dsu(totalCells);
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int idx = i * n + j;
                    for (auto &d : dirs) {
                        int x = i + d[0];
                        int y = j + d[1];
                        int idx1 = x * n + y;
                        if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 1) {
                            dsu.Union(idx, idx1);
                        }
                    }
                }
            }
        }
        for (int i = 0; i < totalCells; i++) {
            if (grid[i/n][i%n] == 1) {
                maxArea = max(maxArea, dsu.getSize(i));
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> st;
                    for (auto &d : dirs) {
                        int x = i + d[0];
                        int y = j + d[1];
                        int idx = x * n + y;
                        if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 1) {
                            st.insert(dsu.find(idx));
                        }
                    }
                    int newSize = 1;
                    for (int x : st) {
                        newSize += dsu.getSize(x);
                    }
                    maxArea = max(maxArea, newSize);
                }
            }
        }
        return maxArea;
    }
};







// class Solution {
// public:
//     vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
//     int n;

//     int dfs(vector<vector<int>>& grid, int i, int j, int id) {
//         if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] != 1) {
//             return 0;
//         }
//         grid[i][j] = id;
//         int count = 1;
//         for (auto &d : dirs) {
//             int x = d[0] + i;
//             int y = d[1] + j;
//             count += dfs(grid, x, y, id);
//         }
//         return count;
//     }

//     int largestIsland(vector<vector<int>>& grid) {
//         n = grid.size();
//         int maxArea = 0;
//         unordered_map<int, int> mp;
//         int id = 2;
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (grid[i][j] == 1) {
//                     int size = dfs(grid, i, j, id);
//                     maxArea = max(maxArea, size);
//                     mp[id] = size;
//                     id++;
//                 }
//             }
//         }
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (grid[i][j] == 0) {
//                     unordered_set<int> st;
//                     for (auto &d : dirs) {
//                         int x = i + d[0];
//                         int y = j + d[1];
//                         if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] != 0) {
//                             st.insert(grid[x][y]);
//                         }
//                     }
//                     int sum = 1;
//                     for (auto &x : st) sum += mp[x];
//                     maxArea = max(maxArea, sum);
//                 }
//             }
//         }
//         return maxArea == 0 ? n * n : maxArea;
//     }
// };

// // TLE 69 / 75
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
// //         vector<vector<bool>> vs(n, vector<bool>(n, false));
// //         for (int i = 0; i < n; i++) {
// //             for (int j = 0; j < n; j++) {
// //                 if (grid[i][j] == 1 && !vs[i][j]) {
// //                     maxArea = max(maxArea, dfs(grid, i, j, vs));
// //                 }
// //             }
// //         }
// //         for (int i = 0; i < n; i++) {
// //             for (int j = 0; j < n; j++) {
// //                 if (grid[i][j] == 0) {
// //                     grid[i][j] = 1;
// //                     vector<vector<bool>> vis(n, vector<bool>(n, false));
// //                     int largest = dfs(grid, i, j, vis);
// //                     grid[i][j] = 0;
// //                     maxArea = max(maxArea, largest);
// //                 }
// //             }
// //         }
// //         return maxArea == 0 ? n * n : maxArea;
// //     }
// // };


// // // TLE 66 / 75
// // // class Solution {
// // // public:
// // //     vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
// // //     int n;

// // //     int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>> &vis) {
// // //         if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == 0 || vis[i][j]) {
// // //             return 0;
// // //         }
// // //         vis[i][j] = true;
// // //         int count = 1;
// // //         for (auto &d : dirs) {
// // //             int x = d[0] + i;
// // //             int y = d[1] + j;
// // //             count += dfs(grid, x, y, vis);
// // //         }
// // //         return count;
// // //     }

// // //     int largestIsland(vector<vector<int>>& grid) {
// // //         n = grid.size();
// // //         int maxArea = 0;
// // //         for (int i = 0; i < n; i++) {
// // //             for (int j = 0; j < n; j++) {
// // //                 if (grid[i][j] == 0) {
// // //                     grid[i][j] = 1;
// // //                     int largest = 0;
// // //                     vector<vector<bool>> vis(n, vector<bool>(n, false));
// // //                     for (int x = 0; x < n; x++) {
// // //                         for (int y = 0; y < n; y++) {
// // //                             if (grid[x][y] == 1 && !vis[x][y]) {
// // //                                 largest = max(largest, dfs(grid, x, y, vis));
// // //                             }
// // //                         }
// // //                     }
// // //                     grid[i][j] = 0;
// // //                     maxArea = max(maxArea, largest);
// // //                 }
// // //             }
// // //         }
// // //         return maxArea == 0 ? n * n : maxArea;
// // //     }
// // // };