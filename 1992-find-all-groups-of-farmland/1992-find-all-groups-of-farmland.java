class Solution {
    public void bfs(int[][] land, int i, int j, int row, int col, int[] max) {
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{i, j});
        int[][] direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.isEmpty()) {
            int[] p = q.poll();
            max[0] = Math.max(max[0], p[0]);
            max[1] = Math.max(max[1], p[1]);
            for (int[] dir : direction) {
                int i_ = p[0] + dir[0];
                int j_ = p[1] + dir[1];
                if (i_ >= 0 && i_ < row && j_ >= 0 && j_ < col && land[i_][j_] == 1) {
                    land[i_][j_] = 0;
                    q.add(new int[]{i_, j_});
                }
            }
        }
    }

    public int[][] findFarmland(int[][] land) {
        int row = land.length;
        int col = land[0].length;
        List<int[]> ansList = new ArrayList<>();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (land[i][j] == 1) {
                    int[] max = new int[]{i, j};
                    bfs(land, i, j, row, col, max);
                    ansList.add(new int[]{i, j, max[0], max[1]});
                }
            }
        }
        int[][] ans = new int[ansList.size()][4];
        for (int i = 0; i < ansList.size(); i++) {
            ans[i] = ansList.get(i);
        }
        return ans;
    }
}


// class Solution {
//     private void dfs(int[][] land, int i, int j, int row, int col, int[] maxCoords) {
//         if (i < 0 || j < 0 || i >= row || j >= col || land[i][j] == 0) {
//             maxCoords[0] = Math.max(i-1, maxCoords[0]);
//             maxCoords[1] = Math.max(j-1, maxCoords[1]);
//             return;
//         }
//         land[i][j] = 0;
//         maxCoords[0] = Math.max(i, maxCoords[0]);
//         maxCoords[1] = Math.max(j, maxCoords[1]);
//         dfs(land, i+1, j, row, col, maxCoords);
//         dfs(land, i-1, j, row, col, maxCoords);
//         dfs(land, i, j+1, row, col, maxCoords);
//         dfs(land, i, j-1, row, col, maxCoords);
//     }
//     public int[][] findFarmland(int[][] land) {
//         int row = land.length, col = land[0].length;
//         List<int[]> ansList = new ArrayList<>();
        
//         for (int i = 0; i < row; i++) {
//             for (int j = 0; j < col; j++) {
//                 if (land[i][j] == 1) {
//                     int[] maxCoords = new int[]{i, j};
//                     dfs(land, i, j, row, col, maxCoords);
//                     ansList.add(new int[]{i, j, maxCoords[0], maxCoords[1]});
//                 }
//             }
//         }
        
//         int[][] ans = new int[ansList.size()][4];
//         for (int i = 0; i < ansList.size(); i++) {
//             ans[i] = ansList.get(i);
//         }
        
//         return ans;
//     }
// }