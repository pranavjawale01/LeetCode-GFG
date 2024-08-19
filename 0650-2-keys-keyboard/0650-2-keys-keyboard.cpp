class Solution {
public:
    int dp[1001][1001];
    
    int solve(int currCountA, int pasteCountA, int n) {
        if (currCountA == n) {
            return 0;
        }

        if (currCountA > n) {
            return 1000;
        }

        if (dp[currCountA][pasteCountA] != -1) {
            return dp[currCountA][pasteCountA];
        }

        int copyPaste = 2 + solve(currCountA + currCountA, currCountA, n);

        int paste = 1 + solve(currCountA + pasteCountA, pasteCountA, n);

        return dp[currCountA][pasteCountA] = min(copyPaste, paste);
    }
    
    int minSteps(int n) {
        if (n == 1) {
            return 0;
        }

        memset(dp, -1, sizeof(dp));

        return 1 + solve(1, 1, n);
    }
};