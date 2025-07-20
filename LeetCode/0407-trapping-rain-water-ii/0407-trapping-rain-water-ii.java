class Solution {
    public int trapRainWater(int[][] heightMap) {
        int m = heightMap.length, n = heightMap[0].length;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        boolean[][] vis = new boolean[m][n];
        for (int i = 0; i < m; i++) {
            pq.offer(new int[]{heightMap[i][0], i, 0});
            vis[i][0] = true;
            pq.offer(new int[]{heightMap[i][n - 1], i, n - 1});
            vis[i][n - 1] = true;
        }
        for (int i = 0; i < n; i++) {
            pq.offer(new int[]{heightMap[0][i], 0, i});
            vis[0][i] = true;
            pq.offer(new int[]{heightMap[m - 1][i], m - 1, i});
            vis[m - 1][i] = true;
        }
        int ans = 0;
        int[][] dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int height = curr[0], i = curr[1], j = curr[2];
            for (int[] dir : dirs) {
                int x = i + dir[0], y = j + dir[1];
                if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y]) {
                    ans += Math.max(0, height - heightMap[x][y]);
                    pq.offer(new int[]{Math.max(height, heightMap[x][y]), x, y});
                    vis[x][y] = true;
                }
            }
        }
        return ans;
    }
}