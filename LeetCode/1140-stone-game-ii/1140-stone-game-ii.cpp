class Solution {
public:
    int n;
    int dp[2][101][101];
    int solve(vector<int> &piles, int person, int i, int M) {
        if (i >= n) {
            return 0;
        }
        if (dp[person][i][M] != -1) {
            return dp[person][i][M];
        }
        int result = (person == 1) ? -1 : INT_MAX;
        int stones = 0;
        for (int x = 1; x <= min(2 * M, n - i); x++) {
            stones += piles[i + x - 1];
            if (person == 1) {
                result = max(result, stones + solve(piles, 0, i+x, max(M, x)));
            } else {
                result = min(result, solve(piles, 1, i+x, max(M, x)));
            }
        }
        return dp[person][i][M] = result;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(dp, -1, sizeof(dp));
        return solve(piles, 1, 0, 1);
    }
};