class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(26, 0);
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            int left = max(0, idx - k);
            int right = min(25, idx + k);
            int longest = 0;
            for (int j = left; j <= right; j++) {
                longest = max(longest, dp[j]);
            }
            dp[idx] = max(dp[idx], longest + 1);
            ans = max(ans, dp[idx]);
        }
        return ans;
    }
};

// class Solution {
// public:
//     int longestIdealString(string s, int k) {
//         int ans = INT_MIN;
//         int n = s.length();
//         vector<int> dp(n, 1);
//         for (int i = 0; i < n; i++) {
//             for (int j = i - 1; j >= 0; j--) {
//                 if (abs(s[i] - s[j]) <= k) {
//                     dp[i] = max(dp[i], dp[j]+1);
//                 }
//             }
//             ans = max(ans, dp[i]);
//         }
//         return ans;
//     }
// };