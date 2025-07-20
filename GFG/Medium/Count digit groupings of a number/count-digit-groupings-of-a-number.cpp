//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int solve(string str, int index, int preSum, vector<vector<int>>& dp) {
	    if (index == str.length()) {
	        return 1;
	    }
	    if (dp[index][preSum] != -1) {
	        return dp[index][preSum];
	    }
	    int curSum = 0, ans = 0;
	    for (int i = index; i < str.length(); i++) {
	        curSum += str[i] - '0';
	        if (curSum >= preSum) {
	            ans += solve(str, i+1, curSum, dp);
	        }
	    }
	    return dp[index][preSum] = ans;
	}
	int TotalCount(string str) {
	    int n = str.length();
	    vector<vector<int>> dp(n, vector<int>(901, -1));
	    return solve(str, 0, 0, dp);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends