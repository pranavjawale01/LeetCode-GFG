//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    double power(double b, int e) {
        // code here
        if (e == 0) return 1;
        if (e < 0) {
            b = 1 / b;
            e = -e;
        }
        double ans = 1;
        while (e) {
            if (e & 1) {
                ans = ans * b;
                e--;
            }
            b = b * b;
            e >>= 1;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    cout << fixed << setprecision(5);
    int t;
    cin >> t;
    while (t--) {
        double b;
        cin >> b;
        int e;
        cin >> e;
        Solution ob;
        cout << ob.power(b, e) << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends