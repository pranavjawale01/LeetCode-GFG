//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        long long sumN = (long long)n * (n + 1) / 2;
        long long sumSquaresN = (long long)n * (n + 1) * (2 * n + 1) / 6;

        long long sumArr = 0;
        long long sumSquaresArr = 0;

        for (int i = 0; i < n; ++i) {
            sumArr += arr[i];
            sumSquaresArr += (long long)arr[i] * arr[i];
        }

        long long diff = sumN - sumArr;
        long long sum = (sumSquaresN - sumSquaresArr) / diff;

        int A = (diff + sum) / 2;
        int B = sum - A;

        return {B, A};
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
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends