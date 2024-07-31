class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n+1, INT_MAX);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            int availWidth = shelfWidth;
            int maxHeight = 0;
            for (int j = i; j < n; j++) {
                int width = books[j][0];
                int height= books[j][1];
                if (availWidth < width) {
                    break;
                }
                availWidth -= width;
                maxHeight = max(maxHeight, height);
                dp[i] = min(dp[i], dp[j+1] + maxHeight);
            }
        }
        return dp[0];
    }
};




// class Solution {
// public:
//     int n;
//     int WIDTH;
//     int dp[1001][1001];
//     int solve(vector<vector<int>> &books, int i, int remain, int maxHt) {
//         if (i >= n) {
//             return maxHt;
//         }
//         if (dp[i][remain] != -1) {
//             return dp[i][remain];
//         }
//         int bookW = books[i][0];
//         int bookH = books[i][1];
//         int keep = INT_MAX;
//         int skip = INT_MAX;
//         if (bookW <= remain) {
//             keep = solve(books, i+1, remain - bookW, max(maxHt, bookH));
//         }
//         skip = maxHt + solve(books, i+1, WIDTH - bookW, bookH);
//         return dp[i][remain] = min(keep, skip);

//     }
//     int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
//         n = books.size();
//         WIDTH = shelfWidth;
//         memset(dp, -1, sizeof(dp));
//         int reaminingWidth = shelfWidth;
//         return solve(books, 0, reaminingWidth, 0);
//     }
// };