class Solution {
    public int orangesRotting(int[][] grid) {
        int[][] dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        Queue<int[]> q = new LinkedList<>();
        int n = grid.length, m = grid[0].length;
        int total = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.offer(new int[]{i, j});
                }
                if (grid[i][j] != 0) {
                    total++;
                }
            }
        }

        int count = 0;
        int days = 0;

        while (!q.isEmpty()) {
            int k = q.size();
            count += k;

            for (int i = 0; i < k; i++) {
                int[] top = q.poll();

                for (int[] dir : dirs) {
                    int x = dir[0] + top[0];
                    int y = dir[1] + top[1];

                    if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1) {
                        grid[x][y] = 2;
                        q.offer(new int[]{x, y});
                    }
                }
            }

            if (!q.isEmpty()) {
                days++;
            }
        }

        return count == total ? days : -1;
    }
}