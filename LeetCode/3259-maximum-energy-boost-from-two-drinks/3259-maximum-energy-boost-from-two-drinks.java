class Solution {
    public long maxEnergyBoost(int[] A, int[] B) {
        long A1 = 0 , B1 = 0 , A2 = 0 , B2 = 0;
        for (int i = 0 ; i < A.length ; i++){
            long currA = A[i] + Math.max(A1 , B2);
            long currB = B[i] + Math.max(B1 , A2);
            A2 = A1 ; A1 = currA;
            B2 = B1 ; B1 = currB;
        }
        return Math.max(A1 , B1);
    }
}





// class Solution {
//     int n;
//     long[][] dp;

//     public long solve(int i, int j, int[] a, int[] b) {
//         if (i >= n) {
//             return 0;
//         }
//         if (dp[i][j] != -1) {
//             return dp[i][j];
//         }
//         long ans = (j == 0) ? a[i] : b[i];
//         ans += Math.max(solve(i + 1, j, a, b), solve(i + 2, 1 - j, a, b));
//         return dp[i][j] = ans;
//     }

//     public long maxEnergyBoost(int[] energyDrinkA, int[] energyDrinkB) {
//         n = energyDrinkA.length;
//         dp = new long[n][2];
//         for (long[] row : dp) {
//             Arrays.fill(row, -1);
//         }
//         return Math.max(solve(0, 0, energyDrinkA, energyDrinkB), solve(0, 1, energyDrinkA, energyDrinkB));
//     }
// }