class Solution {
    private int row, col;
    private void bfs(int[][] grid, int i, int j) {
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{i, j});
        grid[i][j] = 1;
        int[][] dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.isEmpty()) {
            int[] cell = q.poll();
            int x = cell[0], y = cell[1];
            for (int[] dir : dirs) {
                int nx = x + dir[0], ny = y + dir[1];
                if (nx >= 0 && ny >= 0 && nx < row && ny < col && grid[nx][ny] == 0) {
                    grid[nx][ny] = 1;
                    q.add(new int[]{nx, ny});
                }
            }
        }
    }
    public int closedIsland(int[][] grid) {
        row = grid.length;
        col = grid[0].length;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (i == 0 || j == 0 || i == row - 1 || j == col - 1) {
                    if (grid[i][j] == 0) {
                        bfs(grid, i, j);
                    }
                }
            }
        }
        int count = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 0) {
                    bfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
}



/* class Solution {
    private int row, col;
    private void dfs(int[][] grid, int i, int j) {
        if (i < 0 || j < 0 || i >= row || j >= col || grid[i][j] == 1) {
            return;
        }
        grid[i][j] = 1;
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }
    public int closedIsland(int[][] grid) {
        row = grid.length;
        col = grid[0].length;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (i == 0 || j == 0 || i == row - 1 || j == col - 1) {
                    if (grid[i][j] == 0) {
                        dfs(grid, i, j);
                    }
                }
            }
        }
        int count = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 0) {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
}
*/