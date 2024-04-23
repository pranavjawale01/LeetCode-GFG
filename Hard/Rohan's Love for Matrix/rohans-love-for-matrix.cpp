//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int firstElement(int n) {
        // code here
        if (n == 1 || n == 2) {
            return 1;
        }
        int first = 1;
        int second = 1;
        int ans = 0;
        int mod = 1e9 + 7;
        for (int i = 3; i <= n; i++) {
            ans = (first + second) % mod;
            first = second;
            second = ans;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends