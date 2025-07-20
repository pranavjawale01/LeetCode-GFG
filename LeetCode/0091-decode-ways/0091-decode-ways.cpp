class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (n == 0 || s[0] == '0') {
            return 0;
        }
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }
            if (i > 1 && isValidMapping(s[i - 2], s[i - 1])) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }

private:
    bool isValidMapping(char a, char b) {
        int num = (a - '0') * 10 + (b - '0');
        return num >= 10 && num <= 26;
    }
};