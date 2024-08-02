//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int n, m;
    int dp[101][101];
    int solve(string &s1, string &s2, int i, int j) {
        if (i == n) {
            return m - j;
        }
        if (j == m) {
            return n - i;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (s1[i] == s2[j]) {
            return dp[i][j] = solve(s1, s2, i+1, j+1);
        }
        int a = solve(s1, s2, i, j+1);
        int b = solve(s1, s2, i+1, j);
        int c = solve(s1, s2, i+1,j+1);
        return dp[i][j] = 1 + min({a, b, c});
    }
    int editDistance(string str1, string str2) {
        // Code here
        n = str1.length();
        m = str2.length();
        memset(dp, -1, sizeof(dp));
        if (str1 == str2) {
            return 0;
        }
        return solve(str1, str2, 0, 0);
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends