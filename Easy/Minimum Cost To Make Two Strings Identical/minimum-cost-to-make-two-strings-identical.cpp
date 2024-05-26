//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findMinCost(string x, string y, int costX, int costY) {
        // Your code goes here
        int n = x.length(), m = y.length();
        int dp[n+1][m+1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (x[i-1] != y[j-1]) {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                } else {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
            }
        }
        return (n - dp[n][m]) * costX + (m - dp[n][m]) * costY;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;

        int costX, costY;
        cin >> costX >> costY;

        Solution ob;
        cout << ob.findMinCost(x, y, costX, costY);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends