//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        vector<pair<int, char>> order;
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            order.push_back({arr[i], 'a'});
            order.push_back({dep[i], 'd'});
        }
        
        sort(order.begin(), order.end());
        
        int ans = 1;
        int plat = 0;

        for (auto x : order) {
            if (x.second == 'a') {
                plat++;
            } else {
                plat--;
            }
            ans = max(ans, plat);
        }
        
        return ans;
    }
};


// class Solution {
//   public:
//     // Function to find the minimum number of platforms required at the
//     // railway station such that no train waits.
//     int findPlatform(vector<int>& arr, vector<int>& dep) {
//         // Your code here
//         int n = arr.size();
//         sort(arr.begin(), arr.end());
//         sort(dep.begin(), dep.end());
//         int ans = 1, count = 1;
//         int i = 1, j = 0;
//         while (i < n && j < n) {
//             if (arr[i] <= dep[j]) {
//                 count++;
//                 i++;
//             } else {
//                 count--;
//                 j++;
//             }
//             ans = max(ans, count);
//         }
//         return ans;
//     }
// };


//{ Driver Code Starts.
//  Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        vector<int> dep(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int j = 0; j < n; j++) {
            cin >> dep[j];
        }
        Solution ob;
        cout << ob.findPlatform(arr, dep) << endl;
    }
    return 0;
}
// } Driver Code Ends