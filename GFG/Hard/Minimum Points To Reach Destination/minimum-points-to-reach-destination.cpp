//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minPoints(int m, int n, vector<vector<int>> points) 
	{ 
	    // Your code goes here
	    int ans[m][n];
	    ans[m-1][n-1] = points[m-1][n-1] > 0 ? 1 : abs(points[m-1][n-1]) + 1;
	    for (int i = m - 2; i >= 0; i--) {
	        ans[i][n-1] = max(ans[i+1][n-1] - points[i][n-1], 1);
	    }
	    for (int j = n - 2; j >= 0; j--) {
	        ans[m-1][j] = max(ans[m-1][j+1] - points[m-1][j], 1);
	    }
	    for (int i = m - 2; i >= 0; i--) {
	        for (int j = n - 2; j >= 0; j--) {
	            ans[i][j] = max(min(ans[i+1][j], ans[i][j+1]) - points[i][j], 1);
	        }
	    }
	    return ans[0][0];
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;

        vector<vector<int>> a(m, vector<int>(n));

        for(int i = 0; i < m; i++)
        	for(int j = 0; j < n; j++)
        		cin >> a[i][j];

        

	    Solution ob;
	    cout << ob.minPoints(m,n,a) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends