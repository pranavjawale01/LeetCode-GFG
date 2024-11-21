class Solution {
    public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {
        int[][] grid = new int[m][n];
        int[][] directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        for (int[] wall : walls) {
            grid[wall[0]][wall[1]] = 1;
        }

        for (int[] guard : guards) {
            grid[guard[0]][guard[1]] = 2;
        }

        for (int[] guard : guards) {
            int x = guard[0];
            int y = guard[1];

            for (int[] dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];

                while (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] != 1 && grid[nx][ny] != 2) {
                    if (grid[nx][ny] == 0) {
                        grid[nx][ny] = 3;
                    }
                    nx += dir[0];
                    ny += dir[1];
                }
            }
        }

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    count++;
                }
            }
        }

        return count;
    }
}