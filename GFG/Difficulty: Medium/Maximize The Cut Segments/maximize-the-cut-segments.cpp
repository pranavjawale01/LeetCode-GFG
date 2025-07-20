//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution {
public:
    vector<int> dp;
    
    int solve(int n, int sum, int x, int y, int z) {
        if (sum == n) {
            return 0;
        }
        if (sum > n) {
            return INT_MIN;
        }
        if (dp[sum] != -1) {
            return dp[sum];
        }
        int a = solve(n, sum + x, x, y, z);
        int b = solve(n, sum + y, x, y, z);
        int c = solve(n, sum + z, x, y, z);
        
        return dp[sum] = max({a, b, c}) + 1;
    }
    
    // Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z) {
        dp.resize(n + 1, -1);
        int result = solve(n, 0, x, y, z);
        return max(0, result);
    }
};


//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends