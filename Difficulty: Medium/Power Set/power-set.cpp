//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    int n;
	    void solve(string s, string temp, vector<string>& output, int i) {
	        if (i == n) {
	            if (temp.length() > 0) {
    	            output.push_back(temp);
    	        }
	            return;
	        }
	        solve(s, temp + s[i], output, i+1);
	        solve(s, temp, output, i+1);
	    }
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    n = s.length();
		    vector<string> output;
		    solve(s, "", output, 0);
		    sort(output.begin(), output.end());
		    return output;
		}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends