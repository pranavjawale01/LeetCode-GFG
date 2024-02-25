//{ Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends
// Time limit exceeded
// class Solution 
// {
//     public:
//     long long solve(long long n, long long i, vector<long long>& v) {
//         if (n == 0) {
//             return 1;
//         }
//         if (i >= 3 || n < 0) {
//             return 0;
//         }
//         long long take = solve(n-v[i], i, v);
//         long long notTake = solve(n, i+1, v);
//         return take + notTake;
//     }
//     long long int count(long long int n) {
//         vector<long long> v = {3, 5, 10};
//         return solve(n, 0, v);
//     }
// };

class Solution
{
    public:
    // Complete this function
    long long int count(long long int n)
    {
    	// Your code here
    	vector<long long int> dp(n+1, 0);
    	dp[0] = 1;
    	for (int i = 3; i <= n; i++) {
    	    dp[i] += dp[i-3];
    	}
    	for (int i = 5; i <= n; i++) {
    	    dp[i] += dp[i-5];
    	}
    	for (int i = 10; i <= n; i++) {
    	    dp[i] += dp[i-10];
    	}
    	return dp[n];
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		Solution obj;
		cout<<obj.count(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends
