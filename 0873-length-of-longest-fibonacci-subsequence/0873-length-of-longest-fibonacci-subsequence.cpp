class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        vector<vector<int>> dp(n, vector<int>(n, 2));
        for (int i = 0; i < n; i++) mp[arr[i]] = i;
        int max_len = 0;
        for (int j = 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int target = arr[k] - arr[j];
                if (mp.count(target) && mp[target] < j) {
                    int i = mp[target];
                    dp[j][k] = dp[i][j] + 1;
                }
                max_len = max(max_len, dp[j][k]);
            }
        }
        return max_len >= 3 ? max_len : 0;
    }
};







// class Solution {
// public:
//     unordered_map<int, int> mp;
//     vector<vector<int>> dp;

//     int solve(int i, int j, const vector<int> &arr) {
//         if (dp[i][j] != -1) return dp[i][j];
//         int target = arr[j] - arr[i];
//         if (mp.count(target) && mp.at(target) < i) {
//             int k = mp.at(target);
//             dp[i][j] = solve(k, i, arr) + 1;
//             return dp[i][j];
//         }
//         return dp[i][j] = 2;
//     }

//     int lenLongestFibSubseq(vector<int>& arr) {
//         int n = arr.size();
//         dp.resize(n, vector<int>(n, -1));
//         for (int i = 0; i < n; i++) mp[arr[i]] = i;
//         int max_len = 0;
//         for (int i = 1; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 int len = solve(i, j, arr);
//                 if (len >= 3) {
//                     max_len = max(max_len, len);
//                 }
//             }
//         }
//         return max_len >= 3 ? max_len : 0;
//     }
// };