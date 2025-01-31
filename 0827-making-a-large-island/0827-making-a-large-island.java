class Solution {
    private int n;
    private int[][] directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    private int dfs(int[][] grid, int i, int j, int id) {
        if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] != 1) {
            return 0;
        }
        grid[i][j] = id;
        int count = 1;
        for (int[] d : directions) {
            count += dfs(grid, i + d[0], j + d[1], id);
        }
        return count;
    }

    public int largestIsland(int[][] grid) {
        n = grid.length;
        int maxArea = 0;
        Map<Integer, Integer> islandSizes = new HashMap<>();
        int id = 2;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int size = dfs(grid, i, j, id);
                    islandSizes.put(id, size);
                    maxArea = Math.max(maxArea, size);
                    id++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    Set<Integer> adjacentIslands = new HashSet<>();
                    for (int[] d : directions) {
                        int x = i + d[0], y = j + d[1];
                        if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] > 1) {
                            adjacentIslands.add(grid[x][y]);
                        }
                    }
                    int newSize = 1;
                    for (int islandId : adjacentIslands) {
                        newSize += islandSizes.get(islandId);
                    }
                    maxArea = Math.max(maxArea, newSize);
                }
            }
        }

        return maxArea == 0 ? n * n : maxArea;
    }
}