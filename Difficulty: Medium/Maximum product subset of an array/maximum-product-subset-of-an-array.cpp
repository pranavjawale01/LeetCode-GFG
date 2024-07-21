//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
        int n = arr.size();
        if (n == 1) {
            return arr[0];
        }
        long long int pos = 1;
        long long int neg = 1;
        long long int negLar = INT_MIN;
        long long int mod = 1e9 + 7;
        long long int c1 = 0;
        long long int c2 = 0;
        for (auto x : arr) {
            if (x < 0) {
                neg = (neg * (long long int)(x)) % mod;
                negLar = max((long long int)(x), negLar);
                c1++;
            } 
            if (x > 0) {
                pos = (pos * (long long int)(x)) % mod;
                c2++;
            }
        }
        if (c1 <= 1 && c2 == 0) {
            return 0;
        }
        if (neg < 0) {
            neg = neg / negLar;
        }
        return (pos * neg) % mod;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends