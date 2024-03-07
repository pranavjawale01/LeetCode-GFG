//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string longestSubstring(string s, int n) {
        // code here
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        int res_len = 0;
        int i = 0, index = 0;
        for (i = 1; i <= n; i++) {
            for (int  j = i+1; j <= n; j++) {
                if (j - i > dp[i-1][j-1] && s[i-1] == s[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    if (dp[i][j] > res_len) {
                        res_len = dp[i][j];
                        index = max(i, index);
                    }
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        string res = "";
        if (res_len > 0) {
            for (i = index - res_len + 1; i <= index; i++) {
                res += s[i-1];
            }
        }
        if (res == "") {
            return "-1";
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        string S;

        cin >> N;
        cin >> S;

        Solution ob;
        cout << ob.longestSubstring(S, N) << endl;
    }
    return 0;
}
// } Driver Code Ends