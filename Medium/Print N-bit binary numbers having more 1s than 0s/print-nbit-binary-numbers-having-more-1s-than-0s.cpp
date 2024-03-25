//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution {
public:	
    vector<string> ans;

    void solve(int n, string s, int one, int zero) {
        if (n == s.length()) {
            ans.push_back(s);
            return;
        }
        if (one > zero) {
            solve(n, s + '0', one, zero + 1);
        }
        solve(n, s + '1', one + 1, zero);
    }

    vector<string> NBitBinary(int n) {
        solve(n, "", 0, 0);
        auto compare = [](const string& a, const string& b) {
            return a > b;
        };
        sort(ans.begin(), ans.end(), compare);
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends