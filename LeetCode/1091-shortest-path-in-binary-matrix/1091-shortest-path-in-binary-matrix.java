class Solution {
    public int shortestPathBinaryMatrix(int[][] grid) {
        int n = grid.length;
        if (grid[0][0] != 0 || grid[n-1][n-1] != 0) {
            return -1;
        }
        Queue<Pair<Integer, Integer>> q = new LinkedList<>();
        q.offer(new Pair<>(0, 0));
        int level = 1;
        grid[0][0] = 1;
        while (!q.isEmpty()) {
            int len = q.size();
            while (len-- > 0) {
                Pair<Integer, Integer> temp = q.poll();
                int x = temp.getKey();
                int y = temp.getValue();
                if (x == n - 1 && y == n - 1) {
                    return level;
                }
                for (int i = -1; i <= 1; i++) {
                    for (int j = -1; j <= 1; j++) {
                        int newX = x + i;
                        int newY = y + j;
                        if (newX < 0 || newY < 0  || newX >= n || newY >= n || grid[newX][newY] != 0) {
                            continue;
                        }
                        q.offer(new Pair<>(newX, newY));
                        grid[newX][newY] = 1;
                    }
                }
            }
            level++;
        }
        return -1;
    }
}