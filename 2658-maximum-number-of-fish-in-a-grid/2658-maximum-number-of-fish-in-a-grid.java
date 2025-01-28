class DSU {
    private int[] parent;
    private int[] size;

    public DSU(int n) {
        parent = new int[n];
        size = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 0;
        }
    }

    public int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    public void union(int x, int y) {
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

    public void setSize(int x, int fishCount) {
        size[x] = fishCount;
    }

    public int getMaxFishCount() {
        int maxFish = 0;
        for (int fish : size) {
            maxFish = Math.max(maxFish, fish);
        }
        return maxFish;
    }
}

class Solution {
    private int m, n;
    private int[][] dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    public int findMaxFish(int[][] grid) {
        m = grid.length;
        n = grid[0].length;

        int total = m * n;
        DSU dsu = new DSU(total);

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
                    for (int[] dir : dirs) {
                        int x = i + dir[0];
                        int y = j + dir[1];
                        if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] > 0) {
                            dsu.union(idx, x * n + y);
                        }
                    }
                }
            }
        }

        return dsu.getMaxFishCount();
    }
}









// class Solution {
//     int m, n;
//     int[][] dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

//     private int dfs(int i, int j, int[][] grid) {
//         if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
//             return 0;
//         }

//         int fishCount = grid[i][j];
//         grid[i][j] = 0;

//         for (int[] dir : dirs) {
//             int x = i + dir[0];
//             int y = j + dir[1];
//             fishCount += dfs(x, y, grid);
//         }
//         return fishCount;
//     }

//     public int findMaxFish(int[][] grid) {
//         m = grid.length;
//         n = grid[0].length;
//         int maxFish = 0;

//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (grid[i][j] > 0) {
//                     maxFish = Math.max(maxFish, dfs(i, j, grid));
//                 }
//             }
//         }
//         return maxFish;
//     }
// }








// // class Solution {
// //     int m, n;
// //     int[][] dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// //     private int bfs(int i, int j, int[][] grid) {
// //         Queue<int[]> queue = new LinkedList<>();
// //         queue.add(new int[]{i, j});
// //         int fishCount = grid[i][j];
// //         grid[i][j] = 0;

// //         while (!queue.isEmpty()) {
// //             int[] cell = queue.poll();
// //             int x = cell[0], y = cell[1];

// //             for (int[] dir : dirs) {
// //                 int nx = x + dir[0];
// //                 int ny = y + dir[1];

// //                 if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] > 0) {
// //                     queue.add(new int[]{nx, ny});
// //                     fishCount += grid[nx][ny];
// //                     grid[nx][ny] = 0;
// //                 }
// //             }
// //         }
// //         return fishCount;
// //     }

// //     public int findMaxFish(int[][] grid) {
// //         m = grid.length;
// //         n = grid[0].length;
// //         int maxFish = 0;

// //         for (int i = 0; i < m; i++) {
// //             for (int j = 0; j < n; j++) {
// //                 if (grid[i][j] > 0) {
// //                     maxFish = Math.max(maxFish, bfs(i, j, grid));
// //                 }
// //             }
// //         }
// //         return maxFish;
// //     }
// // }