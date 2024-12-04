//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    bool areRotations(string &s1, string &s2) {
        string conc = s1 + s1;
        int m = s1.size(), n = s2.size();
        
        if (m != n) return false;
        
        vector<int> lps(n, 0);
        int j = 1, len = 0;
        
        while (j < n) {
            if (s2[j] == s2[len]) {
                len++;
                lps[j] = len;
                j++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    j++;
                }
            }
        }
        
        int i = 0;
        j = 0;
        while (i < 2 * m) {
            if (conc[i] == s2[j]) {
                i++;
                j++;
                if (j == n) {
                    return true;
                }
            } else {
                if (j > 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        string s2;
        cin >> s1 >> s2;
        Solution sol;
        int result = sol.areRotations(s1, s2);
        if (result) {
            cout << "true" << endl;

        } else {
            cout << "false" << endl;
        }
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends