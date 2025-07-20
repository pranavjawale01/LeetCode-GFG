//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        // code here
        int n = str.size();
        string ans = "";
        
        for (int i = n - 1; i >= 0;) {
            string temp = "";
            while (i >= 0 && str[i] != '.') {
                temp += str[i];
                i--;
            }
            reverse(temp.begin(), temp.end());
            ans += temp;
            if (i > 0) {
                ans += ".";
            }
            i--;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends