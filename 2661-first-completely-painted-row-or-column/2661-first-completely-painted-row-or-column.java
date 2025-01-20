class Solution {
    public int firstCompleteIndex(int[] arr, int[][] mat) {
        int m = mat.length, n = mat[0].length;
        Map<Integer, int[]> mp = new HashMap<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mp.put(mat[i][j], new int[]{i, j});
            }
        }
        int[] rowCount = new int[m];
        int[] colCount = new int[n];
        for (int i = 0; i < arr.length; i++) {
            int val = arr[i];
            int[] pos = mp.get(val);
            int row = pos[0], col = pos[1];
            rowCount[row]++;
            colCount[col]++;
            if (rowCount[row] == n || colCount[col] == m) {
                return i;
            }
        }
        return -1;
    }
}