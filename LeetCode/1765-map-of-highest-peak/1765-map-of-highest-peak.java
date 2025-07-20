class Solution {
    public int[][] highestPeak(int[][] isWater) {
        int[][] dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        int m = isWater.length, n = isWater[0].length;
        int[][] height = new int[m][n];
        for (int[] row : height) Arrays.fill(row, -1);
        Queue<int[]> q = new LinkedList<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    height[i][j] = 0;
                    q.offer(new int[]{i, j});
                }
            }
        }
        while (!q.isEmpty()) {
            int[] curr = q.poll();
            int i = curr[0], j = curr[1];
            for (int[] dir : dirs) {
                int x = i + dir[0], y = j + dir[1];
                if (x >= 0 && y >= 0 && x < m && y < n && height[x][y] == -1) {
                    height[x][y] = height[i][j] + 1;
                    q.offer(new int[]{x, y});
                }
            }
        }
        return height;
    }
}