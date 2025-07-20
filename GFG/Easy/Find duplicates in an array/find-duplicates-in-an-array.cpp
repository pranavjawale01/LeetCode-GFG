//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(long long arr[], int n) {
        // code here
        unordered_map<long long, int> mp;
        set<long long> ans;
        bool flag = false;
        
        for (int i = 0; i < n; i++) {
            mp[arr[i]]++;
            if (mp[arr[i]] > 1) {
                ans.insert(arr[i]);
                flag = true;
            }
        }
        
        if (flag) {
            return vector<int>(ans.begin(), ans.end());
        }
        
        return {-1};
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        long long a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends