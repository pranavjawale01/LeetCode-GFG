class Solution {
    public List<Integer> luckyNumbers (int[][] matrix) {
        int row = matrix.length, col = matrix[0].length;
        int[] minRow = new int[row];
        Arrays.fill(minRow, Integer.MAX_VALUE);
        int[] maxCol = new int[col];
        Arrays.fill(maxCol, Integer.MIN_VALUE);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                minRow[i] = Math.min(minRow[i], matrix[i][j]);
            }
        }
        for (int i = 0; i < col; i++) {
            for (int j = 0; j < row; j++) {
                maxCol[i] = Math.max(maxCol[i], matrix[j][i]);
            }
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (minRow[i] == maxCol[j]) {
                    ans.add(minRow[i]);
                }
            }
        }
        return ans;
    }
}