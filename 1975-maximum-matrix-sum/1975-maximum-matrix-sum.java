class Solution {
    public long maxMatrixSum(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;
        long sum = 0;
        int neg = 0;
        int minEl = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum += Math.abs(matrix[i][j]);
                if (matrix[i][j] < 0) {
                    neg++;
                }
                minEl = Math.min(minEl, Math.abs(matrix[i][j]));
            }
        }

        if (neg % 2 == 0) {
            return sum;
        }

        return sum - 2 * minEl;
    }
}