class DSU {
    int[] parent, size;

    DSU(int n) {
        parent = new int[n];
        size = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void union(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX != rootY) {
            if (size[rootX] > size[rootY]) {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            } else {
                parent[rootX] = rootY;
                size[rootY] += size[rootX];
            }
        }
    }

    int getSize(int x) {
        return size[find(x)];
    }
}

class Solution {
    int[][] dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    public int largestIsland(int[][] grid) {
        int n = grid.length, total = n * n, maxArea = 0;
        DSU dsu = new DSU(total);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int idx = i * n + j;
                    for (int[] d : dirs) {
                        int x = i + d[0], y = j + d[1], idx1 = x * n + y;
                        if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 1) {
                            dsu.union(idx, idx1);
                        }
                    }
                }
            }
        }

        for (int i = 0; i < total; i++) {
            if (grid[i / n][i % n] == 1) {
                maxArea = Math.max(maxArea, dsu.getSize(i));
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    Set<Integer> set = new HashSet<>();
                    for (int[] d : dirs) {
                        int x = i + d[0], y = j + d[1], idx = x * n + y;
                        if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 1) {
                            set.add(dsu.find(idx));
                        }
                    }
                    int newSize = 1;
                    for (int x : set) newSize += dsu.getSize(x);
                    maxArea = Math.max(maxArea, newSize);
                }
            }
        }

        return maxArea;
    }
}










// class Solution {
//     private int n;
//     private int[][] directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

//     private int dfs(int[][] grid, int i, int j, int id) {
//         if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] != 1) {
//             return 0;
//         }
//         grid[i][j] = id;
//         int count = 1;
//         for (int[] d : directions) {
//             count += dfs(grid, i + d[0], j + d[1], id);
//         }
//         return count;
//     }

//     public int largestIsland(int[][] grid) {
//         n = grid.length;
//         int maxArea = 0;
//         Map<Integer, Integer> islandSizes = new HashMap<>();
//         int id = 2;

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (grid[i][j] == 1) {
//                     int size = dfs(grid, i, j, id);
//                     islandSizes.put(id, size);
//                     maxArea = Math.max(maxArea, size);
//                     id++;
//                 }
//             }
//         }

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (grid[i][j] == 0) {
//                     Set<Integer> adjacentIslands = new HashSet<>();
//                     for (int[] d : directions) {
//                         int x = i + d[0], y = j + d[1];
//                         if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] > 1) {
//                             adjacentIslands.add(grid[x][y]);
//                         }
//                     }
//                     int newSize = 1;
//                     for (int islandId : adjacentIslands) {
//                         newSize += islandSizes.get(islandId);
//                     }
//                     maxArea = Math.max(maxArea, newSize);
//                 }
//             }
//         }

//         return maxArea == 0 ? n * n : maxArea;
//     }
// }