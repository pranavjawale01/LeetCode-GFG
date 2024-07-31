class Solution {
public:
    int n;
    int WIDTH;
    int dp[1001][1001];
    int solve(vector<vector<int>> &books, int i, int remain, int maxHt) {
        if (i >= n) {
            return maxHt;
        }
        if (dp[i][remain] != -1) {
            return dp[i][remain];
        }
        int bookW = books[i][0];
        int bookH = books[i][1];
        int keep = INT_MAX;
        int skip = INT_MAX;
        if (bookW <= remain) {
            keep = solve(books, i+1, remain - bookW, max(maxHt, bookH));
        }
        skip = maxHt + solve(books, i+1, WIDTH - bookW, bookH);
        return dp[i][remain] = min(keep, skip);

    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        n = books.size();
        WIDTH = shelfWidth;
        memset(dp, -1, sizeof(dp));
        int reaminingWidth = shelfWidth;
        return solve(books, 0, reaminingWidth, 0);
    }
};