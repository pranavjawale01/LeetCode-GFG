class Solution {
    public int minimumObstacles(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] ans = new int[m][n];
        for (int[] row : ans) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }
        ans[0][0] = 0;
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        pq.offer(new int[]{0, 0, 0});
        int[][] dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int wt = curr[0], i = curr[1], j = curr[2];
            for (int[] dir : dirs) {
                int x = i + dir[0];
                int y = j + dir[1];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    int mass = (grid[x][y] == 1) ? 1 : 0;
                    if (wt + mass < ans[x][y]) {
                        ans[x][y] = wt + mass;
                        pq.offer(new int[]{wt + mass, x, y});
                    }
                }
            }
        }
        return ans[m-1][n-1];
    }
}