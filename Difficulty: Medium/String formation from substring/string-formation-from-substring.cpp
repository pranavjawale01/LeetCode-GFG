//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int isRepeat(string s)
	{
	    // Your code goes here
	    int n = s.size();
        if (n <= 1) return 0;
        
        string doubled = s + s;
        string modified = doubled.substr(1, 2 * n - 2);
        
        if (modified.find(s) != string::npos) {
            return 1;
        }
        
        return 0;
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
   		string str;
   		cin >> str;
        Solution ob;
   		cout << ob.isRepeat(str) << "\n";
   	
cout << "~" << "\n";
}

    return 0;
}
// } Driver Code Ends