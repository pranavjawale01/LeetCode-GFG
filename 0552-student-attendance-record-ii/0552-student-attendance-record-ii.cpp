class Solution {
public:
    int M = 1e9+7;

    int checkRecord(int n) {
        int t[100001][2][3]; 

        for (int A = 0; A <= 1; ++A) {
            for (int L = 0; L <= 2; ++L) {
                t[0][A][L] = 1;
            }
        }

        for(int i = 1; i <= n; i++) {
            for(int A = 0; A <= 1; A++) {
                for(int L = 0; L <= 2; L++) {

                    long long result = t[i-1][A][0];
                    result += (L < 2 ? t[i-1][A][L+1] : 0);
                    result += (A == 0 ? t[i-1][A+1][0]: 0);
                    
                    t[i][A][L] = result % M;
                }
            }
        }

        return t[n][0][0];

    }
};




// class Solution {
// public:
//     int MOD = 1e9 + 7;
//     int memo[100001][2][3];
//     int solve(int n, int absent, int late) {
//         if (absent >= 2 || late >= 3) {
//             return 0;
//         }
//         if (n == 0) {
//             return 1;
//         }
//         if (memo[n][absent][late] != -1) {
//             return memo[n][absent][late];
//         }
//         int A = solve(n-1, absent+1, 0) % MOD;
//         int B = solve(n-1, absent, late+1) % MOD;
//         int C = solve(n-1, absent, 0) % MOD;
//         return memo[n][absent][late] = ((A + B) % MOD + C) % MOD;
//     }
//     int checkRecord(int n) {
//         memset(memo, -1, sizeof(memo));
//         return solve(n, 0, 0);
//     }
// };