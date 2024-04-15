//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query, int q) {
        // Your code goes here;
        int mx = -1;
        for (int i = 0; i < n; i++) {
            mx = max(mx, b[i]);
        }
        vector<int> ans(mx + 1, 0);
        for (int i = 0; i < n; i++) {
            ans[b[i]]++;
        }
        for (int i = 1; i < mx + 1; i++) {
            ans[i] += ans[i - 1];
        }
        vector<int> result;
        for (int i = 0; i < q; i++) {
            if (a[query[i]] > mx) {
                result.push_back(n);
            } else {
                result.push_back(ans[a[query[i]]]);
            }
        }
        return result;
    }
};


//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {

        int n;
        cin >> n;
        vector<int> a, b, ans;
        int input;
        for (int i = 0; i < n; i++) {
            cin >> input;
            a.push_back(input);
        }
        for (int i = 0; i < n; i++) {
            cin >> input;
            b.push_back(input);
        }
        int q;
        cin >> q;
        vector<int> query;
        for (int i = 0; i < q; i++) {
            cin >> input;
            query.push_back(input);
        }
        Solution obj;
        ans = obj.countElements(a, b, n, query, q);
        for (int i = 0; i < q; i++) {
            cout << ans[i] << endl;
        }
    }
    return 0;
}
// } Driver Code Ends