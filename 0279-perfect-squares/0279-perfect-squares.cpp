class Solution {
public:
    int numSquares(int n) {
        vector<int> arr(n+1, 100001);
        arr[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j*j <= i; j++) {
                arr[i] = min(arr[i], 1 + arr[i - j*j]);
            }
        }
        return arr[n];
    }
};

// class Solution {
// public:
//     int memo[10001];
//     int solve(int n) {
//         if (n == 0) {
//             return 0;
//         }
//         if (memo[n] != -1) {
//             return memo[n];
//         }
//         int minCount = INT_MAX;
//         for (int i = 1; i*i <= n; i++) {
//             int result = 1 + solve(n - i*i);
//             minCount = min(minCount, result);
//         }
//         return memo[n] = minCount;
//     }
//     int numSquares(int n) {
//         memset(memo, -1, sizeof(memo));
//         return solve(n);
//     }
// };