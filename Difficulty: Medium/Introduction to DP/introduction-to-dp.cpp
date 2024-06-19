//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int topDown(int n) {
        vector<long long int> dp(n + 1, -1);
        return fibonacciTopDown(n, dp);
    }

    long long int bottomUp(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        
        vector<long long int> dp(n + 1, 0);
        dp[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % (1000000007);
        }
        
        return dp[n];
    }

    long long int fibonacciTopDown(int n, vector<long long int>& dp) {
        if (n <= 1) return n;
        if (dp[n] != -1) return dp[n];
        
        dp[n] = (fibonacciTopDown(n - 1, dp) + fibonacciTopDown(n - 2, dp)) % (1000000007);
        
        return dp[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends