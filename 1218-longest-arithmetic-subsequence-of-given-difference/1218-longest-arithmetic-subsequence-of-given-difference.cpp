class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        int n = arr.size();
        unordered_map<int, int> dp;
        int maxlen = 1;
        for (int i = 0; i < n; i++) {
            int num = arr[i];
            if (dp.find(num - diff) != dp.end()) {
                dp[num] = dp[num - diff] + 1;
            } else {
                dp[num] = 1;
            }
            maxlen = max(maxlen, dp[num]);
        }
        return maxlen;
    }
};



// TLE
// class Solution {
// public:
//     int longestSubsequence(vector<int>& arr, int diff) {
//         int n = arr.size();
//         vector<int> dp(n, 1);
//         int maxlen = 1;
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < i; j++) {
//                 if (arr[i] - arr[j] == diff) {
//                     dp[i] = max(dp[i], dp[j] + 1);
//                     maxlen = max(maxlen, dp[i]);
//                 }
//             }
//         }
//         return maxlen;
//     }
// };