class Solution {
    public int[][] spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int[][] dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int[][] ans = new int[rows * cols][2];
        int step = 0;
        int dir = 0;
        int index = 0;
        
        ans[index++] = new int[]{rStart, cStart};
        
        while (index < rows * cols) {
            if (dir == 0 || dir == 2) {
                step++;
            }
            for (int i = 0; i < step; i++) {
                rStart += dirs[dir][0];
                cStart += dirs[dir][1];
                if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                    ans[index++] = new int[]{rStart, cStart};
                }
            }
            dir = (dir + 1) % 4;
        }
        
        return ans;
    }
}