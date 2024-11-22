class Solution {
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        int ans = 0;

        for (int[] curr : matrix) {
            int[] inv = new int[n];
            for (int i = 0; i < n; i++) {
                inv[i] = curr[i] == 0 ? 1 : 0;
            }

            int count = 0;
            for (int[] row : matrix) {
                if (Arrays.equals(row, curr) || Arrays.equals(row, inv)) {
                    count++;
                }
            }

            ans = Math.max(ans, count);
        }

        return ans;
    }
}