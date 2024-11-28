//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int myAtoi(char *s) {
        // Your code here
        int ans = 0;
        int i = 0;
        bool neg = false;
        while (s[i] != '\0' && s[i] == ' ') i++;
        if (s[i] == '-') {
            i++;
            neg = true;
        }
        while (s[i] != '\0' && (s[i] >= '0' && s[i] <= '9')) {
            int digit = s[i] - '0';
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > 7)) {
                return neg ? INT_MIN : INT_MAX;
            }
            ans = ans * 10 + digit;
            i++;
        }
        return neg ? -ans : ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends