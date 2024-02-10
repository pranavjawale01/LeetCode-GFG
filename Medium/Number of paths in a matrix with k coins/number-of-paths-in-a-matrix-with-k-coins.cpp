//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int dp[101][101][101];
    long long solve(int n, int k, vector<vector<int>> &arr, int i, int j) {
        if (k < 0) {
            return 0;
        }
        if (i == n - 1 && j == n - 1) {
            if (k == arr[i][j]) {
                return 1;
            }
            return 0;
        }
        if (dp[i][j][k] != -1) {
            return dp[i][j][k];
        }
        long long right = 0, down = 0; 
        if (j + 1 < n) {
            right = solve(n, k - arr[i][j], arr, i, j+1);
        }
        if (i + 1 < n) {
            down  = solve(n, k - arr[i][j], arr, i+1, j);
        }
        return dp[i][j][k] = right + down;
    }
    long long numberOfPath(int n, int k, vector<vector<int>> &arr){
        memset(dp, -1, sizeof(dp));
        return solve(n, k, arr, 0, 0);
    }
};

//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n, vector<int>(n, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends