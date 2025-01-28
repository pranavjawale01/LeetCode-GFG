class Solution {
    int m, n;
    int[][] dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    private int bfs(int i, int j, int[][] grid) {
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{i, j});
        int fishCount = grid[i][j];
        grid[i][j] = 0;

        while (!queue.isEmpty()) {
            int[] cell = queue.poll();
            int x = cell[0], y = cell[1];

            for (int[] dir : dirs) {
                int nx = x + dir[0];
                int ny = y + dir[1];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] > 0) {
                    queue.add(new int[]{nx, ny});
                    fishCount += grid[nx][ny];
                    grid[nx][ny] = 0;
                }
            }
        }
        return fishCount;
    }

    public int findMaxFish(int[][] grid) {
        m = grid.length;
        n = grid[0].length;
        int maxFish = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    maxFish = Math.max(maxFish, bfs(i, j, grid));
                }
            }
        }
        return maxFish;
    }
}