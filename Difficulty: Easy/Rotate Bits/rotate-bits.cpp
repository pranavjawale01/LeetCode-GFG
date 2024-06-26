//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        vector <int> rotate (int n, int d)
        {
            //code here.
            d = d % 16;
            vector<int> result(2);
            int bits = 16;
            result[0] = (n << d | n >> (bits - d)) & 0xFFFF;
            result[1] = (n >> d | n << (bits - d)) & 0xFFFF;
            
            return result;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        
        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate (n, d);
        cout << res[0] << endl << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends