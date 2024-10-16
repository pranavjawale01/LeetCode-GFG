//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> ans;
    void solve(int sum, vector<int> &arr, int n, int i) {
        if (i >= n) {
            ans.push_back(sum);
            return;
        }
        solve(sum + arr[i], arr, n, i+1);
        solve(sum, arr, n, i+1);
    }
    vector<int> subsetSums(vector<int> arr, int n) {
        // Write Your Code here
        solve(0, arr, n, 0);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends