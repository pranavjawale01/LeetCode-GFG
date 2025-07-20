//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

const int mod = 1e9 + 7;

class Solution {
  public:
    int nthFibonacci(int n){
        // code here
        if (n == 1 || n == 2) {
            return 1;
        }
        long long int n1 = 1, n2 = 1, ans = 0;
        for (int i = 3; i <= n; i++) {
            ans = (n1 + n2) % mod;
            n2 = n1 % mod;
            n1 = ans % mod;
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
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends