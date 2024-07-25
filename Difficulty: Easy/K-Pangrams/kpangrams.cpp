//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:

    bool kPangram(string str, int k) {
        // code here
        vector<int> count(26, 0);
        unordered_set<char> unique;
        int len = 0;
        for (char c : str) {
            if (isalpha(c)) {
                c = tolower(c);
                count[c - 'a']++;
                unique.insert(c);
                len++;
            }
        }
        if (len < 26) {
            return false;
        }
        if (k > 25) {
            return true;
        } else {
            if (unique.size() + k >= 26) {
                return true;
            } else {
                return false;
            }
        }
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends