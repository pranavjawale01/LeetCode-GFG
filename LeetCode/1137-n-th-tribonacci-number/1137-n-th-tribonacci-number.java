class Solution {
    int[] memo;

    public int tribonacci(int n) {
        memo = new int[n + 1];
        Arrays.fill(memo, -1);
        return helper(n);
    }

    private int helper(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        if (memo[n] != -1) return memo[n];
        memo[n] = helper(n - 1) + helper(n - 2) + helper(n - 3);
        return memo[n];
    }
}

// class Solution {
//     public int tribonacci(int n) {
//         if (n == 0) {
//             return 0;
//         }
//         if (n == 1 || n == 2) {
//             return 1;
//         }
//         int t0 = 0, t1 = 1, t2 = 1;
//         for (int i = 3; i <= n; i++) {
//             int temp = t0 + t1 + t2;
//             t0 = t1;
//             t1 = t2;
//             t2 = temp;
//         }
//         return t2;
//     }
// }