//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string smallestNumber(int s, int d) {
        // code here
        int i = 1;
        string ans = "";
        while (i <= d) {
            int num = s - (d - i) * 9 <= 0 ? 0 : s - (d - i) * 9;
            if (num == 0 && i == 1) {
                num = 1;
            }
            if (num > 9) {
                return "-1";
            }
            ans += (num + '0');
            i++;
            s -= num;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends