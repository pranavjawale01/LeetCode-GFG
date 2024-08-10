class Solution {
    int[] x = {-1, 0, 0, 1};
    int[] y = {0, -1, 1, 0};

    private boolean isValid(int i, int j, int m, int n, int[][] grid) {
        return i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == 0;
    }

    private void dfs(int i, int j, int m, int n, boolean[][] visited, int[][] grid) {
        visited[i][j] = true;
        for (int k = 0; k < 4; k++) {
            int newX = i + x[k];
            int newY = j + y[k];
            if (isValid(newX, newY, m, n, grid)) {
                if (!visited[newX][newY]) {
                    dfs(newX, newY, m, n, visited, grid);
                }
            }
        }
    }

    public int regionsBySlashes(String[] grid) {
        int m = grid.length * 3;
        int n = grid[0].length() * 3;
        int[][] newGrid = new int[m][n];
        boolean[][] visited = new boolean[m][n];

        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length(); j++) {
                if (grid[i].charAt(j) == '/') {
                    newGrid[i * 3][j * 3 + 2] = 1;
                    newGrid[i * 3 + 1][j * 3 + 1] = 1;
                    newGrid[i * 3 + 2][j * 3] = 1;
                } else if (grid[i].charAt(j) == '\\') {
                    newGrid[i * 3][j * 3] = 1;
                    newGrid[i * 3 + 1][j * 3 + 1] = 1;
                    newGrid[i * 3 + 2][j * 3 + 2] = 1;
                }
            }
        }

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (newGrid[i][j] == 0 && !visited[i][j]) {
                    dfs(i, j, m, n, visited, newGrid);
                    count++;
                }
            }
        }
        return count;
    }
}