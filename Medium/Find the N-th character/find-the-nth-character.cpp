//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    string solve(string s, int n) {
        string ans = "";
        for (char c : s) {
            if (c == '0') {
                ans += "01";
            } else {
                ans += "10";
            }
            if (ans.length() > n) {
                break;
            }
        }
        return ans;
    }
    char nthCharacter(string s, int r, int n) {
        //code here
        for (int i = 0; i < r; i++) {
            s = solve(s, n);
        }
        return s[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends