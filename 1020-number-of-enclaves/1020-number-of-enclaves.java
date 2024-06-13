class Solution {
    public void bfs(int[][] grid, int i, int j) {
        int row = grid.length;
        int col = grid[0].length;
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{i, j});
        grid[i][j] = 0;

        int[][] directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        while (!queue.isEmpty()) {
            int[] cell = queue.poll();
            int x = cell[0], y = cell[1];
            
            for (int[] dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];
                
                if (nx >= 0 && nx < row && ny >= 0 && ny < col && grid[nx][ny] == 1) {
                    grid[nx][ny] = 0;
                    queue.offer(new int[]{nx, ny});
                }
            }
        }
    }
    
    public int numEnclaves(int[][] grid) {
        int row = grid.length, col = grid[0].length;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (i == 0 || j == 0 || i == row - 1 || j == col - 1) {
                    if (grid[i][j] == 1) {
                        bfs(grid, i, j);
                    }
                }
            }
        }
        int count = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    count++;
                }
            }
        }
        return count;
    }
}



// class Solution {
//     public void dfs(int[][] grid, int i, int j) {
//         if (i < 0 || j < 0 || i == grid.length || j == grid[0].length || grid[i][j] != 1) {
//             return;
//         }
//         grid[i][j] = 0;
//         dfs(grid, i+1, j);
//         dfs(grid, i-1, j);
//         dfs(grid, i, j+1);
//         dfs(grid, i, j-1);
//     }
//     public int numEnclaves(int[][] grid) {
//         int row = grid.length, col = grid[0].length;
//         for (int i = 0; i < row; i++) {
//             for (int j = 0; j < col; j++) {
//                 if (i == 0 || j == 0 || i == row - 1 || j == col - 1) {
//                     if (grid[i][j] == 1) {
//                         dfs(grid, i, j);
//                     }
//                 }
//             }
//         }
//         int count = 0;
//         for (int i = 0; i < row; i++) {
//             for (int j = 0; j < col; j++) {
//                 if (grid[i][j] == 1) {
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// }