//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int DivisibleByEight(string s){
        //code here
        int n = s.length(), i = 0, ans = 0;
        if (n > 3) {
            i = n - 4;
        }
        for (; i < n; i++) {
            ans = ans * 10 + (s[i] - '0');
        }
        if (ans % 8 == 0) return 1;
        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends