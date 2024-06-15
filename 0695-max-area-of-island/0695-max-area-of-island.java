class Solution {
    private int row, col;
    
    private int bfs(int[][] grid, int i, int j) {
        Queue<int[]> q = new ArrayDeque<>();
        grid[i][j] = 0;
        q.offer(new int[]{i, j});
        int area = 1;
        
        while (!q.isEmpty()) {
            int[] current = q.poll();
            int x = current[0];
            int y = current[1];
            
            int[][] directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            
            for (int[] dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];
                
                if (nx >= 0 && nx < row && ny >= 0 && ny < col && grid[nx][ny] == 1) {
                    grid[nx][ny] = 0;
                    area++;
                    q.offer(new int[]{nx, ny});
                }
            }
        }
        
        return area;
    }
    
    public int maxAreaOfIsland(int[][] grid) {
        row = grid.length;
        col = grid[0].length;
        int maxArea = 0;
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    maxArea = Math.max(maxArea, bfs(grid, i, j));
                }
            }
        }
        
        return maxArea;
    }
}



// class Solution {
//     private int row, col;
//     private int dfs(int[][] grid, int i, int j) {
//         if (i < 0 || j < 0 || i >= row || j >= col || grid[i][j] == 0) {
//             return 0;
//         }
//         grid[i][j] = 0;
//         return 1 + dfs(grid, i+1, j) + dfs(grid, i-1, j) + dfs(grid, i, j+1) + dfs(grid, i, j-1);
//     }
//     public int maxAreaOfIsland(int[][] grid) { 
//         row = grid.length;
//         col = grid[0].length;
//         int ans = 0;
//         for (int i = 0; i < row; i++) {
//             for (int j = 0; j < col; j++) {
//                 if (grid[i][j] == 1) {
//                     ans = Math.max(ans, dfs(grid, i, j));
//                 }
//             }
//         }
//         return ans;
//     }
// }