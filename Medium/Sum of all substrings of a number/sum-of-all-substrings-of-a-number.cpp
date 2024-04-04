//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s) {
        // your code here
        long long ans = 0, previous = 0, mod = 1e9+7;
        for (int i = 0; i < s.length(); i++) {
            long long curr = (previous*10) % mod + (s[i] - '0')*(i+1) % mod;
            ans = (ans + curr) % mod;
            previous = curr;
        }
        return ans;
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
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}

// } Driver Code Ends