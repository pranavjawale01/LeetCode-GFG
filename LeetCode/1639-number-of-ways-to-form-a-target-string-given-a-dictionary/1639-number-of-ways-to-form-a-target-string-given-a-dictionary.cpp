class Solution {
public:
    int MOD = 1e9 + 7;
    int numWays(vector<string>& words, string target) {
        int k = words[0].size(), m = target.size();
        
        vector<vector<long long>> freq(26, vector<long long>(k));
        
        for (int i = 0; i < k; i++) {
            for (string &x : words) {
                freq[x[i] - 'a'][i]++;
            }
        }
        
        vector<vector<long long>> dp(m + 1, vector<long long>(k + 1));
        dp[0][0] = 1;

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= k; j++) {
                if (j < k) {
                    dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD;
                    if (i < m && j < k) {
                        dp[i + 1][j + 1] = (dp[i + 1][j + 1] + freq[target[i] - 'a'][j] * dp[i][j]) % MOD;
                    }
                }
            }
        }

        return dp[m][k];
    }
};







// class Solution {
// public:
//     int dp[1001][1001];
//     int m, k, MOD = 1e9 + 7;

//     int solve(int i, int j, vector<vector<long long>> &freq, string &target) {
//         if (i == m) return 1;
//         if (j == k) return 0;
//         if (dp[i][j] != -1) return dp[i][j];
//         int take = freq[target[i] - 'a'][j] * solve(i+1, j+1, freq, target) % MOD;
//         int nottake = solve(i, j+1, freq, target) % MOD;
//         return dp[i][j] = (take + nottake) % MOD;
//     }

//     int numWays(vector<string>& words, string target) {
//         k = words[0].size();
//         m = target.size();
//         vector<vector<long long>> freq(26, vector<long long>(k));
//         for (int col = 0; col < k; col++) {
//             for (string &x : words) {
//                 freq[x[col] - 'a'][col]++;
//             }
//         }
//         memset(dp, -1, sizeof(dp));
//         return solve(0, 0, freq, target);
//     }
// };