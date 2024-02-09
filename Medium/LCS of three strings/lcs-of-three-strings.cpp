//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        int t[21][21][21];
        int solve(string A, string B, string C, int n1, int n2, int n3, int i, int j, int k) {
            if (i >= n1 || j >= n2 || k >= n3) {
                return 0;
            }
            if (t[i][j][k] != -1) {
                return t[i][j][k];
            }
            if (A[i] == B[j] && B[j] == C[k]) {
                return t[i][j][k] = 1 + solve(A, B, C, n1, n2, n3, i+1, j+1, k+1);
            }
            return t[i][j][k] = max({solve(A, B, C, n1, n2, n3, i+1, j, k), solve(A, B, C, n1, n2, n3, i, j+1, k), solve(A, B, C, n1, n2, n3, i, j, k+1)});
        }
        int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
        {
            memset(t, -1, sizeof(t));
            return solve(A, B, C, n1, n2, n3, 0, 0, 0);
        }
};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        Solution obj;
        cout << obj.LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends