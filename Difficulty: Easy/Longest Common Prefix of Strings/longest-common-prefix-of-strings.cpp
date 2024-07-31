//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        sort(arr.begin(), arr.end());
        int n = arr[0].size();
        int m = arr.size();
        if (arr[0][0] != arr[m-1][0]) {
            return "-1";
        }
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (arr[0][i] != arr[m-1][i]) {
                break;
            }
            ans += arr[0][i];
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends