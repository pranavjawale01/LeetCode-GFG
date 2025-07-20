//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int mod = 1e9+7;
    
    int solve(string s1, string s2, int i, int j, vector<vector<int>> &dp) {
        if (s2.length() == j) {
            return 1;
        }
        if (s1.length() == i) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int x = 0, y = 0;
        if (s1[i] == s2[j]) {
            x = solve(s1, s2, i+1, j+1, dp);
        }
        y = solve(s1, s2, i+1, j, dp);
        return dp[i][j] = (x + y) % mod;
    }
    
    int countWays(string s1, string s2) {
        // code here
        vector<vector<int>> dp(s1.length(), vector<int>(s2.length(), -1));
        return solve(s1, s2, 0, 0, dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        Solution obj;
        int res = obj.countWays(s1, s2);

        cout << res << endl;
    }
}

// } Driver Code Ends