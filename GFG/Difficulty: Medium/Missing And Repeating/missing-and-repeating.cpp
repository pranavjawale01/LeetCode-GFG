//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        long long sumN = (long long) n * (n + 1) / 2;
        long long sumSqN = (long long) n * (n + 1) * (2 * n + 1) / 6;
        
        long long sumArr = 0, sumSqArr = 0;
        for (int i = 0; i < n; i++) {
            sumArr += arr[i];
            sumSqArr += (long long) arr[i] * arr[i];
        }
        
        long long diffSum = sumN - sumArr; // missing - repeating
        long long diffSqSum = sumSqN - sumSqArr; // (missing ^ 2 - repeating ^ 2)
        
        long long sumMissingRepeating = diffSqSum / diffSum; // missing + repeating
        
        int missing = (diffSum + sumMissingRepeating) / 2;
        int repeating = sumMissingRepeating - missing;
        
        return {repeating, missing};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends