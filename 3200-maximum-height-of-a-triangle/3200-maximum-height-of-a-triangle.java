class Solution {
    public int solve(int red, int blue) {
        int height = 0;
        int row = 1;
        
        while (true) {
            if (row % 2 == 1) {
                if (red >= row) {
                    red -= row;
                    height++;
                } else {
                    break;
                }
            } else {
                if (blue >= row) {
                    blue -= row;
                    height++;
                } else {
                    break;
                }
            }
            row++;
        }
        
        return height;
    }
    
    public int maxHeightOfTriangle(int red, int blue) {
        return Math.max(solve(red, blue), solve(blue, red));
    }
}