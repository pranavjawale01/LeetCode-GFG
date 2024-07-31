class Solution {
public:
    int n;
    int WIDTH;
    int solve(vector<vector<int>> &books, int i, int remain, int maxHt) {
        if (i >= n) {
            return maxHt;
        }
        int bookW = books[i][0];
        int bookH = books[i][1];
        int keep = INT_MAX;
        int skip = INT_MAX;
        if (bookW <= remain) {
            keep = solve(books, i+1, remain - bookW, max(maxHt, bookH));
        }
        skip = maxHt + solve(books, i+1, WIDTH - bookW, bookH);
        return min(keep, skip);

    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        n = books.size();
        WIDTH = shelfWidth;
        int reaminingWidth = shelfWidth;
        return solve(books, 0, reaminingWidth, 0);
    }
};