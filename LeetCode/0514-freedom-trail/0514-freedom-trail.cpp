class Solution {
public:
    int countSteps(int ringIndex, int i, int n) {
        int dist = abs(i - ringIndex);
        int wrapAround = n - dist;
        return min(dist, wrapAround);
    }
    int findRotateSteps(string ring, string key) {
        int n = ring.length(), m = key.length();
        vector<vector<int>> dp(n, vector<int>(m+1, INT_MAX));
        for (int i = 0; i < n; i++) {
            dp[i][m] = 0;
        }
        for (int keyIndex = m - 1; keyIndex >= 0; keyIndex--) {
            for (int ringIndex = 0; ringIndex < n; ringIndex++) {
                int result = INT_MAX;
                for (int i = 0; i < n; i++) {
                    if (ring[i] == key[keyIndex]) {
                        int totalSteps = countSteps(ringIndex, i, n) + 1 + dp[i][keyIndex+1];
                        result = min(result, totalSteps);
                    }
                }
                dp[ringIndex][keyIndex] = result;
            }
        }
        return dp[0][0];
    }
};


// class Solution {
// public:
//     int dp[101][101];
//     int countSteps(int ringIndex, int i, int n) {
//         int dist   = abs(i - ringIndex);
//         int wrapAround = n - dist;
//         return min(dist, wrapAround);
//     }
//     int solve(int ringIndex, int keyIndex, string &ring, string &key) {
//         if (keyIndex == key.length()) {
//             return 0;
//         }
//         if (dp[ringIndex][keyIndex] != -1) {
//             return dp[ringIndex][keyIndex];
//         }
//         int result = INT_MAX;
//         for (int i = 0; i < ring.length(); i++) {
//             if (ring[i] == key[keyIndex]) {
//                 int totalSteps = countSteps(ringIndex, i, ring.length()) + 1 + solve(i, keyIndex+1, ring, key);
//                 result = min(result, totalSteps);
//             }
//         }
//         return dp[ringIndex][keyIndex] = result;
//     }
//     int findRotateSteps(string ring, string key) {
//         memset(dp, -1, sizeof(dp));
//         return solve(0, 0, ring, key); 
//     }
// };