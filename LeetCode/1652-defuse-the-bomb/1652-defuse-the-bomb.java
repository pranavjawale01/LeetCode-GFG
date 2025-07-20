class Solution {
    public int[] decrypt(int[] code, int k) {
        int n = code.length;
        if (k == 0) {
            return new int[n];
        }
        int[] extendedCode = new int[2 * n];
        System.arraycopy(code, 0, extendedCode, 0, n);
        System.arraycopy(code, 0, extendedCode, n, n);
        int[] result = new int[n];
        if (k > 0) {
            for (int i = 0; i < n; i++) {
                int sum = 0;
                for (int j = 1; j <= k; j++) {
                    sum += extendedCode[i + j];
                }
                result[i] = sum;
            }
        } else {
            for (int i = 0; i < n; i++) {
                int sum = 0;
                for (int j = 1; j <= -k; j++) {
                    sum += extendedCode[i + n - j];
                }
                result[i] = sum;
            }
        }
        return result;
    }
}