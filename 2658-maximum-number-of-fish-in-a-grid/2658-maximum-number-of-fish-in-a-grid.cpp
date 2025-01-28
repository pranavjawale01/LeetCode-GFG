class DSU {
    vector<int> parent;
    vector<int> size;

public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 0;
        }
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    
    void Union(int x, int y) {
        int xpar = find(x);
        int ypar = find(y);
        if (xpar == ypar) {
            return;
        }
        if (size[xpar] > size[ypar]) {
            parent[ypar] = xpar;
            size[xpar] += size[ypar];
        } else {
            parent[xpar] = ypar;
            size[ypar] += size[xpar];
        }
    }

    void setSize(int x, int fishCount) {
        size[x] = fishCount;
    }

    int getMaxFishCount() {
        return *max_element(size.begin(), size.end());
    }
};
    
class Solution {
public:
    int m, n;
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int findMaxFish(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int total = m * n;

        DSU dsu(total);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    dsu.setSize(i * n + j, grid[i][j]);
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    int idx = i * n + j;
                    for (auto &d : dirs) {
                        int x = i + d[0];
                        int y = j + d[1];
                        if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] > 0) {
                            dsu.Union(i * n + j, x * n + y);
                        }
                    }
                }
            }
        }
        return dsu.getMaxFishCount();
    }
};








// class Solution {
// public:
//     int m, n;
//     vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

//     int dfs(int i, int j, vector<vector<int>> &grid) {
//         if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
//             return 0;
//         }
//         int fishCount = grid[i][j];
//         grid[i][j] = 0;
//         for (auto &d : dirs) {
//             int x = i + d[0];
//             int y = j + d[1];
//             fishCount += dfs(x, y, grid);
//         }
//         return fishCount;
//     }

//     int findMaxFish(vector<vector<int>>& grid) {
//         m = grid.size(), n = grid[0].size();
//         int fish = 0;
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (grid[i][j] > 0) {
//                     fish = max(fish, dfs(i, j, grid));
//                 }
//             }
//         }
//         return fish;
//     }
// };


// // class Solution {
// // public:
// //     int m, n;
// //     vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// //     int bfs(int i, int j, vector<vector<int>> &grid) {
// //         queue<pair<int, int>> q;
// //         q.push({i, j});
// //         int fishCount = grid[i][j];
// //         grid[i][j] = 0;
// //         while (!q.empty()) {
// //             i = q.front().first;
// //             j = q.front().second;
// //             q.pop();
// //             for (auto &d : dirs) {
// //                 int x = d[0] + i;
// //                 int y = d[1] + j;
// //                 if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] > 0) {
// //                     q.push({x, y});
// //                     fishCount += grid[x][y];
// //                     grid[x][y] = 0;
// //                 }
// //             }
// //         }
// //         return fishCount;
// //     }

// //     int findMaxFish(vector<vector<int>>& grid) {
// //         m = grid.size(), n = grid[0].size();
// //         int fish = 0;
// //         for (int i = 0; i < m; i++) {
// //             for (int j = 0; j < n; j++) {
// //                 if (grid[i][j] > 0) {
// //                     fish = max(fish, bfs(i, j, grid));
// //                 }
// //             }
// //         }
// //         return fish;
// //     }
// // };