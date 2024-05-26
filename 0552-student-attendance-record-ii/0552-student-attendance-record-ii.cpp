class Solution {
public:
    int MOD = 1e9 + 7;
    int memo[100001][2][3];
    int solve(int n, int absent, int late) {
        if (absent >= 2 || late >= 3) {
            return 0;
        }
        if (n == 0) {
            return 1;
        }
        if (memo[n][absent][late] != -1) {
            return memo[n][absent][late];
        }
        int A = solve(n-1, absent+1, 0) % MOD;
        int B = solve(n-1, absent, late+1) % MOD;
        int C = solve(n-1, absent, 0) % MOD;
        return memo[n][absent][late] = ((A + B) % MOD + C) % MOD;
    }
    int checkRecord(int n) {
        memset(memo, -1, sizeof(memo));
        return solve(n, 0, 0);
    }
};