class Solution {
    public void bfs(char[][] grid, int i, int j, int row, int col) {
        Queue<Pair<Integer, Integer>> q = new LinkedList<>();
        q.offer(new Pair<>(i, j));
        grid[i][j] = '0';
        int[][] direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.isEmpty()) {
            Pair<Integer, Integer> it = q.poll();
            int x = it.getKey();
            int y = it.getValue();
            for (int[] dir : direction) {
                int i_ = x + dir[0];
                int j_ = y + dir[1];
                if (i_ < 0 || j_ < 0 || i_ >= row || j_ >= col || grid[i_][j_] == '0') {
                    continue;
                } else {
                    q.offer(new Pair<>(i_, j_));
                    grid[i_][j_] = '0';
                }
            }
        }   
    }
    
    public int numIslands(char[][] grid) {
        int row = grid.length, col = grid[0].length, count = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    bfs(grid, i, j, row, col);
                }
            }
        }
        return count;
    }
}

// class Solution {
//     public void dfs(char[][] grid, int i, int j, int row, int col) {
//         if (i < 0 || j < 0 || i >= row || j >= col || grid[i][j] == '0') {
//             return;
//         }
//         grid[i][j] = '0';
//         dfs(grid, i+1, j, row, col);
//         dfs(grid, i-1, j, row, col);
//         dfs(grid, i, j+1, row, col);
//         dfs(grid, i, j-1, row, col);
//     }
//     public int numIslands(char[][] grid) {
//         int row = grid.length, col = grid[0].length;
//         int count = 0;
//         for (int i = 0; i < row; i++) {
//             for (int j = 0; j < col; j++) {
//                 if (grid[i][j] == '1') {
//                     dfs(grid, i, j, row, col);
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// }