class Solution {
    public long maxPoints(int[][] points) {
        int row = points.length, col = points[0].length;
        long[] ans = new long[col];
        
        for (int i = 0; i < col; i++) {
            ans[i] = points[0][i];
        }
        
        for (int i = 1; i < row; i++) {
            long[] left = new long[col];
            long[] right = new long[col];

            left[0] = ans[0];
            for (int j = 1; j < col; j++) {
                left[j] = Math.max(left[j-1] - 1, ans[j]);
            }

            right[col-1] = ans[col-1];
            for (int j = col - 2; j >= 0; j--) {
                right[j] = Math.max(right[j+1] - 1, ans[j]);
            }

            for (int j = 0; j < col; j++) {
                ans[j] = points[i][j] + Math.max(left[j], right[j]);
            }
        }
        
        return Arrays.stream(ans).max().getAsLong();
    }
}