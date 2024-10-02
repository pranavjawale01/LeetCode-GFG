//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function to find maximum product subarray
    long long maxProduct(vector<int> &arr) {
        // code here
        int n = arr.size();
        long long ans = 1ll;
        long long maxSub = INT_MIN;
        for (int i = 0; i < n; i++) {
            ans = (long long) ans * arr[i];
            maxSub = max(maxSub, ans);
            if (ans == 0) ans = 1;
        }
        ans = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans = (long long) ans * arr[i];
            maxSub = max(maxSub, ans);
            if (ans == 0) ans = 1;
        }
        return maxSub;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends