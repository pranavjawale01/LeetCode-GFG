class Solution {
    public int numSquares(int n) {
        int[] arr = new int[n + 1];
        arr[0] = 0;
        for (int i = 1; i <= n; i++) {
            arr[i] = Integer.MAX_VALUE;
            for (int j = 1; j * j <= i; j++) {
                arr[i] = Math.min(arr[i], 1 + arr[i - j * j]);
            }
        }
        return arr[n];
    }
}

// class Solution {
//     private int[] memo = new int[10001];
//     public int solve(int n) {
//         if (n == 0) {
//             return 0;
//         }
//         if (memo[n] != -1) {
//             return memo[n];
//         }
//         int minCount = Integer.MAX_VALUE;
//         for (int i = 1; i * i <= n; i++) {
//             int result = 1 + solve(n - i*i);
//             minCount = Math.min(minCount, result);
//         }
//         return memo[n] = minCount;
//     }
//     public int numSquares(int n) {
//         Arrays.fill(memo, -1);
//         return solve(n);
//     }
// }