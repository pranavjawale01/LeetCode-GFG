//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        // your code here
        string ans = "";
        int i = s1.size() - 1, j = s2.size() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += (s1[i--] == '1' ? 1 : 0);
            if (j >= 0) sum += (s2[j--] == '1' ? 1 : 0);
            ans.push_back(sum % 2 + '0');
            carry = sum / 2;
        }
        reverse(ans.begin(), ans.end());
        while (ans.size() > 1 && ans[0] == '0') ans.erase(ans.begin());
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends