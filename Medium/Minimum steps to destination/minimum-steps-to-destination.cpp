//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minSteps(int d) {
        // code here
        int temp = 0, ans = 0;
        while (temp < d) {
            ans++;
            temp += ans;
        }
        if (temp == d) {
            return ans;
        }
        int diff = temp - d;
        if (diff % 2 == 0) return ans;
        return ans % 2 == 0 ? ans + 1: ans+2;
    }
};



// class Solution {
//   public:
//     int minSteps(int d) {
//         // code here
//         d = abs(d);
//         int sum = 0, steps = 0;
//         while (sum < d || abs(d - sum) % 2 != 0) {
//             steps++;
//             sum += steps;
//         }
//         return steps;
//     }
// };




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int d;
        cin >> d;

        Solution ob;
        cout << ob.minSteps(d) << "\n";
    }
    return 0;
}
// } Driver Code Ends