//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // l and r are input array
    // maxx : maximum in r[]
    // n: size of array
    // arr[] : declared globally with size equal to maximum in l[] and r[]
    // Function to find the maximum occurred integer in all ranges.
    int maxOccured(int n, int l[], int r[], int maxx) {
        // Your code here
        vector<int> arr(maxx+2, 0);
        for (int i = 0; i < n; i++) {
            arr[l[i]]++;
            arr[r[i]+1]--;
        }
        int sum = 0;
        for (int i = 0; i <= maxx; i++) {
            arr[i] += sum;
            sum = arr[i];
        }
        int ans = 0;
        for (int i = 0; i <= maxx; i++) {
            if (arr[i] > arr[ans]) {
                ans = i;
            }
        }
        return ans;
    }
};



// class Solution {
//   public:
//     // l and r are input array
//     // maxx : maximum in r[]
//     // n: size of array
//     // arr[] : declared globally with size equal to maximum in l[] and r[]
//     // Function to find the maximum occurred integer in all ranges.
//     int maxOccured(int n, int l[], int r[], int maxx) {

//         // Your code here
//         vector<int> count(maxx+1);
//         for (int i = 0; i < n; i++) {
//             for (int j = l[i]; j <= r[i]; j++) {
//                 count[j]++;
//             }
//         }
//         int ans = 0;
//         int frq = 0;
//         for (int i = 0; i <= maxx; i++) {
//             if (frq < count[i]) {
//                 frq = count[i];
//                 ans = i;
//             }
//         }
//         return ans;
//     }
// };


// class Solution {
//   public:
//     // l and r are input array
//     // maxx : maximum in r[]
//     // n: size of array
//     // arr[] : declared globally with size equal to maximum in l[] and r[]
//     // Function to find the maximum occurred integer in all ranges.
//     int maxOccured(int n, int l[], int r[], int maxx) {
//         // Your code here
//         map<int, int> mp;
//         for (int i = 0; i < n; i++) {
//             for (int j = l[i]; j <= r[i]; j++) {
//                 mp[j]++;
//             }
//         }
//         int ans = INT_MIN;
//         int freq = 0;
//         for (auto x : mp) {
//             if (x.second > freq) {
//                 freq = x.second;
//                 ans = x.first;
//             }
//         }
//         return ans;
//     }
// };


//{ Driver Code Starts.

int main() {

    int t;

    // taking testcases
    cin >> t;

    while (t--) {
        int n;

        // taking size of array
        cin >> n;
        int l[n];
        int r[n];

        // adding elements to array L
        for (int i = 0; i < n; i++) {
            cin >> l[i];
        }

        int maxx = 0;

        // adding elements to array R
        for (int i = 0; i < n; i++) {

            cin >> r[i];
            if (r[i] > maxx) {
                maxx = r[i];
            }
        }
        Solution ob;

        // calling maxOccured() function
        cout << ob.maxOccured(n, l, r, maxx) << endl;
    }

    return 0;
}
// } Driver Code Ends