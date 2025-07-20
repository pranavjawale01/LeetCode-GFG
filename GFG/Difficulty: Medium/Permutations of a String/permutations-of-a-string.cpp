//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<string> ans;

    void solve(string &s, int idx) {
        if (idx == s.size()) {
            ans.push_back(s);
            return;
        }
        unordered_set<char> used;
        for (int i = idx; i < s.size(); i++) {
            if (used.find(s[i]) != used.end()) {
                continue;
            }
            used.insert(s[i]);
            swap(s[idx], s[i]);
            solve(s, idx + 1);
            swap(s[idx], s[i]);
        }
    }

    vector<string> findPermutation(string &s) {
        sort(s.begin(), s.end());
        solve(s, 0);
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends