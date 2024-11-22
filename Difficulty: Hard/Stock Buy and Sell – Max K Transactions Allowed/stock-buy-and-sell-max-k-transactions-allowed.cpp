//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int K, int N, int prices[]) {
        // code here
        if (N == 0 || K == 0) return 0;
        vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(K+1, vector<int>(2, 0)));
        for (int i = N - 1; i >= 0; i--) {
            for (int k = 1; k <= K; k++) {
                dp[i][k][1] = max(dp[i+1][k][0] - prices[i], dp[i+1][k][1]);
                dp[i][k][0] = max(prices[i] + dp[i+1][k-1][1], dp[i+1][k][0]);
            }
        }
        return dp[0][K][1];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends