class Solution {
    public int checkRecord(int n) {
        int M = 1000000007;
        int[][][] t = new int[100001][2][3];

        for (int A = 0; A <= 1; ++A) {
            for (int L = 0; L <= 2; ++L) {
                t[0][A][L] = 1;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int A = 0; A <= 1; A++) {
                for (int L = 0; L <= 2; L++) {

                    long result = t[i - 1][A][0];
                    result += (L < 2 ? t[i - 1][A][L + 1] : 0);
                    result += (A == 0 ? t[i - 1][A + 1][0] : 0);

                    t[i][A][L] = (int) (result % M);
                }
            }
        }

        return t[n][0][0];
    }
}


// class Solution {
//     private final int MOD = 1000000007;
//     private int[][][] memo = new int[100001][2][3];

//     private int solve(int n, int absent, int late) {
//         if (absent >= 2 || late >= 3) {
//             return 0;
//         }
//         if (n == 0) {
//             return 1;
//         }
//         if (memo[n][absent][late] != -1) {
//             return memo[n][absent][late];
//         }
//         int A = solve(n - 1, absent + 1, 0) % MOD;
//         int B = solve(n - 1, absent, late + 1) % MOD;
//         int C = solve(n - 1, absent, 0) % MOD;
//         return memo[n][absent][late] = ((A + B) % MOD + C) % MOD;
//     }

//     public int checkRecord(int n) {
//         for (int i = 0; i < 100001; i++) {
//             for (int j = 0; j < 2; j++) {
//                 Arrays.fill(memo[i][j], -1);
//             }
//         }
//         return solve(n, 0, 0);
//     }
// }