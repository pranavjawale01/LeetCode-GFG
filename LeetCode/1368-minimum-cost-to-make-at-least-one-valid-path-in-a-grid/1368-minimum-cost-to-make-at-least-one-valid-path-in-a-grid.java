class Solution {
    public int minCost(int[][] grid) {
        int[][] dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int m = grid.length;
        int n = grid[0].length;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> Integer.compare(a[0], b[0]));
        int[][] res = new int[m][n];
        for (int[] row : res) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }
        pq.offer(new int[]{0, 0, 0});
        res[0][0] = 0;
        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int currCost = curr[0], i = curr[1], j = curr[2];
            if (res[i][j] < currCost) {
                continue;
            }
            for (int dir = 0; dir < 4; dir++) {
                int x = i + dirs[dir][0];
                int y = j + dirs[dir][1];
                if (x >= 0 && y >= 0 && x < m && y < n) {
                    int gridDir = grid[i][j];
                    int dirCost = ((gridDir - 1 != dir) ? 1 : 0);
                    int newCost = currCost + dirCost;
                    if (newCost < res[x][y]) {
                        res[x][y] = newCost;
                        pq.offer(new int[]{newCost, x, y});
                    }
                }
            }
        }
        return res[m-1][n-1];
    }
}