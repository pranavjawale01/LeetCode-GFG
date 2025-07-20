class Solution {
    private int m, n;
    private final int[][] directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    private void bfs(int[][] heights, Queue<int[]> queue, boolean[][] reach) {
        while (!queue.isEmpty()) {
            int[] cell = queue.poll();
            int i = cell[0], j = cell[1];
            for (int[] dir : directions) {
                int x = i + dir[0], y = j + dir[1];
                if (x >= 0 && y >= 0 && x < m && y < n && !reach[x][y] && heights[x][y] >= heights[i][j]) {
                    reach[x][y] = true;
                    queue.offer(new int[]{x, y});
                }
            }
        }
    }

    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        List<List<Integer>> result = new ArrayList<>();
        if (heights == null || heights.length == 0) return result;

        m = heights.length;
        n = heights[0].length;
        boolean[][] pacific = new boolean[m][n];
        boolean[][] atlantic = new boolean[m][n];
        Queue<int[]> pacificQueue = new LinkedList<>();
        Queue<int[]> atlanticQueue = new LinkedList<>();

        for (int i = 0; i < m; i++) {
            pacificQueue.offer(new int[]{i, 0});
            atlanticQueue.offer(new int[]{i, n - 1});
            pacific[i][0] = true;
            atlantic[i][n - 1] = true;
        }

        for (int j = 0; j < n; j++) {
            pacificQueue.offer(new int[]{0, j});
            atlanticQueue.offer(new int[]{m - 1, j});
            pacific[0][j] = true;
            atlantic[m - 1][j] = true;
        }

        bfs(heights, pacificQueue, pacific);
        bfs(heights, atlanticQueue, atlantic);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.add(Arrays.asList(i, j));
                }
            }
        }

        return result;
    }
}




// class Solution {
//     private int m, n;
//     private final int[][] dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

//     private void dfs(int[][] heights, boolean[][] reach, int i, int j) {
//         reach[i][j] = true;
//         for (int[] dir : dirs) {
//             int x = i + dir[0];
//             int y = j + dir[1];
//             if (x < 0 || y < 0 || x >= m || y >= n || reach[x][y] || heights[x][y] < heights[i][j]) {
//                 continue;
//             }
//             dfs(heights, reach, x, y);
//         }
//     }

//     public List<List<Integer>> pacificAtlantic(int[][] heights) {
//         m = heights.length;
//         n = heights[0].length;
//         boolean[][] pacific = new boolean[m][n];
//         boolean[][] atlantic = new boolean[m][n];

//         for (int i = 0; i < m; i++) {
//             dfs(heights, pacific, i, 0);
//             dfs(heights, atlantic, i, n - 1);
//         }

//         for (int j = 0; j < n; j++) {
//             dfs(heights, pacific, 0, j);
//             dfs(heights, atlantic, m - 1, j);
//         }

//         List<List<Integer>> result = new ArrayList<>();
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (pacific[i][j] && atlantic[i][j]) {
//                     List<Integer> cell = new ArrayList<>();
//                     cell.add(i);
//                     cell.add(j);
//                     result.add(cell);
//                 }
//             }
//         }

//         return result;
//     }
// }