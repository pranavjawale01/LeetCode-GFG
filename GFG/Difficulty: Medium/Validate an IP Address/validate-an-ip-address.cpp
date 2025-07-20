//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */

class Solution {
  public:
    int isValid(string str) {
        // code here
        int n = str.size();
        int i = 0, segments = 0;
        
        while (i < n) {
            if (segments == 4) {
                return false;
            }
            int num = 0;
            int digits = 0;
            
            while (i < n && str[i] != '.') {
                if (!isdigit(str[i])) {
                    return false;
                }
                num = num * 10 + (str[i] - '0');
                if (++digits > 3) {
                    return false;
                }
                i++;
            }
            
            if (num > 255) {
                return false;
            }
            
            segments++;
            i++;
        }

        return segments == 4;
    }
};


//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends