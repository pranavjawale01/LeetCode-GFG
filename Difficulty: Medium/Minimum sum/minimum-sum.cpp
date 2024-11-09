//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
        sort(arr.begin(), arr.end());
        vector<int> a1, a2;
        int i = 0, j = 0, n = arr.size();
        while (i < n) {
            a1.push_back(arr[i++]);
            if (i < n) {
                a2.push_back(arr[i++]);
            }
        }
        reverse(a1.begin(), a1.end());
        reverse(a2.begin(), a2.end());
        string ans;
        int carry = 0;
        i = 0, j = 0;
        while (i < a1.size() && j < a2.size()) {
            int digit = a1[i++] + a2[j++] + carry;
            carry = digit / 10;
            digit %= 10;
            ans += to_string(digit);
        }
        while (i < a1.size()) {
            int digit = a1[i++] + carry;
            carry = digit / 10;
            digit %= 10;
            ans += to_string(digit);
        }
        while (j < a2.size()) {
            int digit = a2[j++] + carry;
            carry = digit / 10;
            digit %= 10;
            ans += to_string(digit);
        }
        while (carry) {
            int digit = carry;
            carry = digit / 10;
            digit %= 10;
            ans += to_string(digit);
        }
        reverse(ans.begin(), ans.end());
        i = 0;
        while (i < ans.size() && ans[i] == '0') i++;
        ans = ans.substr(i);
        if (ans.empty()) return "0";
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends