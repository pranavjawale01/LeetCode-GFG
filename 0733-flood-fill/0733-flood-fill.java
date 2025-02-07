class Solution {
    private int[][] directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    private int m, n;

    public void dfs(int[][] image, int i, int j, int originalColor, int newColor) {
        if (i < 0 || j < 0 || i >= m || j >= n || image[i][j] != originalColor) {
            return;
        }
        
        image[i][j] = newColor;
        
        for (int[] dir : directions) {
            dfs(image, i + dir[0], j + dir[1], originalColor, newColor);
        }
    }

    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        m = image.length;
        n = image[0].length;
        int originalColor = image[sr][sc];

        if (originalColor != color) {
            dfs(image, sr, sc, originalColor, color);
        }

        return image;
    }
}