//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int A, int B)
    {
        //code here
        vector<vector<int>> dp(A, vector<int>(B, 0));
        for (int i = 0; i < A; i++) {
            dp[i][0] = 1;
        }
        for (int j = 0; j < B; j++) {
            dp[0][j] = 1;
        }
        for (int i = 1; i < A; i++) {
            for (int j = 1; j < B; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[A-1][B-1];
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends