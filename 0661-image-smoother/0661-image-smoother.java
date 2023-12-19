class Solution {
    public int[][] imageSmoother(int[][] img) {
        int row = img.length, col = img[0].length;
        int[][] rImg = new int[row][col];
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int count = 0, total = 0;
                for (int ni = Math.max(0, i-1); ni < Math.min(row, i+2); ni++) {
                    for (int nj = Math.max(0, j-1); nj < Math.min(col, j+2); nj++) {
                        total += img[ni][nj];
                        count += 1;
                    }
                }
                rImg[i][j] = total / count;
            }
        }
        return rImg;
    }
}