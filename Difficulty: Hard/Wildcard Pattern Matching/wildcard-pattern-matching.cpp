//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    vector<vector<int>> dp;

    int solve(string& a, string& b, int i, int j) {
        if (i == a.length() && j == b.length()) {
            return 1;
        }
        if (i == a.length()) {
            return 0;
        }
        if (j == b.length()) {
            return (a[i] == '*' ? solve(a, b, i + 1, j) : 0);
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int matchEmpty = 0, matchChar = 0, matchBoth = 0;
        
        if (a[i] == '*') {
            matchEmpty = solve(a, b, i + 1, j); // match '*' with empty sequence
            matchChar = solve(a, b, i, j + 1);  // match '*' with one character
        } else if (a[i] == '?' || a[i] == b[j]) {
            matchBoth = solve(a, b, i + 1, j + 1);
        }

        return dp[i][j] = matchEmpty | matchChar | matchBoth;
    }

    int wildCard(string pattern, string str) {
        dp.assign(pattern.length(), vector<int>(str.length(), -1));
        return solve(pattern, str, 0, 0);
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends