class Solution {
    private static int[][] dirs = {{2, 1}, {-2, 1}, {2, -1}, {-2, -1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};

    private void bfs(int x, int y, int idx, int[][] minDist, int[][] pos) {
        int N = 50;
        int[][] dist = new int[N][N];
        for (int[] row : dist) {
            Arrays.fill(row, -1);
        }
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{x, y});
        dist[x][y] = 0;
        while (!q.isEmpty()) {
            int[] curr = q.poll();
            int currX = curr[0];
            int currY = curr[1];
            for (int[] dir : dirs) {
                int newX = currX + dir[0];
                int newY = currY + dir[1];
                if (newX >= 0 && newX < N && newY >= 0 && newY < N && dist[newX][newY] == -1) {
                    dist[newX][newY] = dist[currX][currY] + 1;
                    q.add(new int[]{newX, newY});
                }
            }
        }
        for (int i = 0; i < pos.length; i++) {
            int x_ = pos[i][0];
            int y_ = pos[i][1];
            minDist[idx][i] = dist[x_][y_];
        }
    }

    private int solve(int[][] minDist, int idx, int mask, int n, boolean alice, int[][][] dp) {
        if (mask == 0) {
            return 0;
        }
        if (dp[idx][mask][alice ? 1 : 0] != -1) {
            return dp[idx][mask][alice ? 1 : 0];
        }
        int result = alice ? Integer.MIN_VALUE : Integer.MAX_VALUE;
        for (int i = 1; i < n; i++) {
            if ((mask & (1 << (i - 1))) != 0) {
                int moves = minDist[idx][i];
                if (alice) {
                    result = Math.max(result, moves + solve(minDist, i, mask ^ (1 << i - 1), n, !alice, dp));
                } else {
                    result = Math.min(result, moves + solve(minDist, i, mask ^ (1 << i - 1), n, !alice, dp));
                }
            }
        }
        return dp[idx][mask][alice ? 1 : 0] = result;
    }

    public int maxMoves(int kx, int ky, int[][] positions) {
        int n = positions.length;
        int[][] pos = new int[n + 1][2];
        pos[0][0] = kx;
        pos[0][1] = ky;
        System.arraycopy(positions, 0, pos, 1, n);

        int[][] minDist = new int[n + 1][n + 1];
        for (int i = 0; i < minDist.length; i++) {
            Arrays.fill(minDist[i], 0);
        }

        for (int i = 0; i < pos.length; i++) {
            int x = pos[i][0];
            int y = pos[i][1];
            bfs(x, y, i, minDist, pos);
        }

        boolean alice = true;
        int[][][] dp = new int[pos.length][1 << n][2];
        for (int[][] arr : dp) {
            for (int[] subArr : arr) {
                Arrays.fill(subArr, -1);
            }
        }

        return solve(minDist, 0, (1 << n) - 1, pos.length, alice, dp);
    }
}