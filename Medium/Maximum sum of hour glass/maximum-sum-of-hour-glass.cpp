//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findMaxSum(int n, int m, vector<vector<int>> mat) {
        // code here
        if (n < 3 || m < 3) {
            return -1;
        }
        int ans = INT_MIN;
        for (int i = 2; i < n; i++) {
            int sum = 0;
            for (int j = 1; j < m - 1; j++) {
                sum = mat[i-2][j-1] + mat[i-2][j] + mat[i-2][j+1] + mat[i-1][j] + mat[i][j-1] + mat[i][j] + mat[i][j+1];
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, i, j;
        cin >> N >> M;
        vector<vector<int>> Mat(N, vector<int>(M));
        for (i = 0; i < N; i++)
            for (j = 0; j < M; j++) cin >> Mat[i][j];
        Solution ob;
        cout << ob.findMaxSum(N, M, Mat) << "\n";
    }
}
// } Driver Code Ends