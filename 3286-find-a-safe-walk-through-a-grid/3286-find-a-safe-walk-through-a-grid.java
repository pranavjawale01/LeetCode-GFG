class Solution {
    public boolean findSafeWalk(List<List<Integer>> grid, int health) {
        int n = grid.size();
        int m = grid.get(0).size();
        int[][] dp = new int[n][m];
        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], -1);
        }
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{0, 0, health - grid.get(0).get(0)});
        dp[0][0] = health - grid.get(0).get(0);
        int[][] dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.isEmpty()) {
            int[] cell = q.poll();
            int x = cell[0], y = cell[1], val = cell[2];
            if (x == n-1 && y == m-1) {
                if (val > 0) {
                    return true;
                }
            }
            for (int[] dir : dirs) {
                int newX = x + dir[0];
                int newY = y + dir[1];
                if (newX >= 0 && newY >= 0 && newX < n && newY < m) {
                    int newVal = val - grid.get(newX).get(newY);
                    if (newVal > 0 && newVal > dp[newX][newY]) {
                        q.offer(new int[]{newX, newY, newVal});
                        dp[newX][newY] = newVal;
                    }
                }
            }
        }
        return false;
    }
}