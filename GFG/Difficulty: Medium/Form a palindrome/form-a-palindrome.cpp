//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int dp[501][501];
    int solve(int i, int j, string &s) {
        if (i >= j) {
            return dp[i][j] = 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (s[i] == s[j]) {
            return dp[i][j] = solve(i+1, j-1, s);
        }
        int addFirst = solve(i+1, j, s) + 1;
        int addLast  = solve(i, j-1, s) + 1;
        return dp[i][j] = min(addFirst, addLast);
    }
    int countMin(string str) {
        //complete the function here
        memset(dp, -1, sizeof(dp));
        return solve(0, str.size()-1, str);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends