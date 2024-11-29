class Solution {
    public int minimumTime(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;

        boolean[][] vis = new boolean[m][n];
        int[][] dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.offer(new int[]{grid[0][0], 0, 0});

        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int time = curr[0], i = curr[1], j = curr[2];
            if (i == m - 1 && j == n - 1) return time;
            if (vis[i][j]) continue;
            vis[i][j] = true;

            for (int[] dir : dirs) {
                int r = i + dir[0], c = j + dir[1];
                if (r < 0 || r >= m || c < 0 || c >= n || vis[r][c]) continue;
                if (grid[r][c] <= time + 1) {
                    pq.offer(new int[]{time + 1, r, c});
                } else if ((grid[r][c] - time) % 2 == 0) {
                    pq.offer(new int[]{grid[r][c] + 1, r, c});
                } else {
                    pq.offer(new int[]{grid[r][c], r, c});
                }
            }
        }

        return -1;
    }
}