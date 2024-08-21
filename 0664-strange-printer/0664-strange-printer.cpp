class Solution {
public:
    int n;
    int dp[101][101];
    int solve(int l, int r, string &s) {
        if (l == r) {
            return 1;
        }
        if (l > r) {
            return 0;
        }
        if (dp[l][r] != -1) {
            return dp[l][r];
        }
        int i = l + 1;
        while (i <= r && s[i] == s[l]) {
            i++;
        }
        if (i == r + 1) {
            return 1;
        }
        int basic = 1 + solve(i, r, s);
        int greedy = INT_MAX;
        for (int j = i; j <= r; j++) {
            if (s[j] == s[l]) {
                int ans = solve(i, j-1, s) + solve(j, r, s);
                greedy = min(greedy, ans);
            }
        }
        return dp[l][r] = min(basic, greedy);
    }
    int strangePrinter(string s) {
        n = s.length();
        memset(dp, -1, sizeof(dp));
        return solve(0, n-1, s);
    }
};