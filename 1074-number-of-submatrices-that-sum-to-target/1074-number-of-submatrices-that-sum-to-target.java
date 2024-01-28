class Solution {
    public int numSubmatrixSumTarget(int[][] matrix, int target) {
        int row = matrix.length, col = matrix[0].length;

        for (int i = 0; i < row; i++) {
            for (int j = 1; j < col; j++) {
                matrix[i][j] += matrix[i][j - 1];
            }
        }

        int result = 0;

        for (int i = 0; i < col; i++) {
            for (int j = i; j < col; j++) {
                Map<Integer, Integer> mp = new HashMap<>();
                mp.put(0, 1);
                int cumSum = 0;

                for (int k = 0; k < row; k++) {
                    cumSum += matrix[k][j] - (i > 0 ? matrix[k][i - 1] : 0);
                    if (mp.containsKey(cumSum - target)) {
                        result += mp.get(cumSum - target);
                    }
                    mp.put(cumSum, mp.getOrDefault(cumSum, 0) + 1);
                }
            }
        }

        return result;
    }
}