class Solution {
public:
    unordered_set<string> st;
    int dp[301];
    int n;

    bool solve(string &s, int i) {
        if (i == n) {
            return true;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        for (int len = 1; len <= n - i; len++) {
            string temp = s.substr(i, len);
            if (st.find(temp) != st.end() && solve(s, i + len)) {
                return dp[i] = true;
            }
        }
        return dp[i] = false;
    }

    bool wordBreak(string &s, vector<string>& wordDict) {
        st = unordered_set<string>(wordDict.begin(), wordDict.end());
        n = s.length();
        memset(dp, -1, sizeof(dp));
        return solve(s, 0);
    }
};

// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         unordered_set<string> dict(wordDict.begin(), wordDict.end());
//         int n = s.length();
//         vector<bool> dp(n + 1, false);
//         dp[0] = true;
//         for (int i = 1; i <= n; i++) {
//             for (int j = 0; j < i; j++) {
//                 if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
//                     dp[i] = true;
//                     break;
//                 }
//             }
//         }
//         return dp[n];
//     }
// };