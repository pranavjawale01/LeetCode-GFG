//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int longestUniqueSubstr(string &s) {
        unordered_map<char, int> mp;
        int ans = 0;
        int n = s.size();
        int i = 0, j = 0;

        while (j < n) {
            mp[s[j]]++;

            while (mp[s[j]] > 1) {
                mp[s[i]]--;
                if (mp[s[i]] == 0) {
                    mp.erase(s[i]);
                }
                i++;
            }

            ans = max(ans, j - i + 1);
            j++;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends