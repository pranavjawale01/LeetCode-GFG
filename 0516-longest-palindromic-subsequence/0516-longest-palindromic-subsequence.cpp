class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len = 1; len <= n; len++) {
            for (int start = 0; start <= (n - len); start++) {
                int end = start + len - 1;
                if (len == 1) {
                    dp[start][end] = 1;
                    continue;
                }
                if (s[start] == s[end]) {
                    dp[start][end] = 2 + dp[start+1][end-1];
                } else {
                    dp[start][end] = max(dp[start+1][end], dp[start][end-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};


// class Solution {
// public:
//     int dp[1000][1000];
//     int solve(string &s, int start, int end) {
//         if (start == end) {
//             return 1;
//         }
//         if (start > end) {
//             return 0;
//         }
//         if (dp[start][end] != -1) {
//             return dp[start][end];
//         }
//         if (s[start] == s[end]) {
//             return dp[start][end] = 2 + solve(s, start+1, end-1);
//         }
//         return dp[start][end] = max(solve(s, start+1, end), solve(s, start, end-1));
//     }
//     int longestPalindromeSubseq(string s) {
//         memset(dp, -1, sizeof(dp));
//         return solve(s, 0, s.size()-1);
//     }
// };