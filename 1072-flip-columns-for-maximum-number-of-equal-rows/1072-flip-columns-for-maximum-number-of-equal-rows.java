class Solution {
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        Map<String, Integer> patternCount = new HashMap<>();

        for (int[] row : matrix) {
            StringBuilder pattern = new StringBuilder();
            int firstValue = row[0];

            for (int i = 0; i < n; i++) {
                pattern.append(row[i] == firstValue ? 'p' : 'j');
            }

            String patternStr = pattern.toString();
            patternCount.put(patternStr, patternCount.getOrDefault(patternStr, 0) + 1);
        }

        int ans = 0;
        for (int count : patternCount.values()) {
            ans = Math.max(ans, count);
        }

        return ans;
    }
}









// class Solution {
//     public int maxEqualRowsAfterFlips(int[][] matrix) {
//         int m = matrix.length, n = matrix[0].length;
//         int ans = 0;

//         for (int[] curr : matrix) {
//             int[] inv = new int[n];
//             for (int i = 0; i < n; i++) {
//                 inv[i] = curr[i] == 0 ? 1 : 0;
//             }

//             int count = 0;
//             for (int[] row : matrix) {
//                 if (Arrays.equals(row, curr) || Arrays.equals(row, inv)) {
//                     count++;
//                 }
//             }

//             ans = Math.max(ans, count);
//         }

//         return ans;
//     }
// }