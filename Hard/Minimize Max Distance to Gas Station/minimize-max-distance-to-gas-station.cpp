//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool check(double mid, vector<int> &arr, int k) {
        int count = 0;
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            int dist = arr[i] - arr[i-1];
            if (dist <= mid) {
                continue;
            } else {
                count += (dist / mid);
            }
        }
        return count <= k;
    }
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        int n = stations.size();
        double low = 0.0;
        double high = 1e9;
        double ans = -1;
        while (high - low > 1e-6) {
            double mid = low + (high - low) / 2.0;
            if (check(mid, stations, k)) {
                ans = mid;
                high = mid;
            } else {
                low = mid;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
    }
    return 0;
}
// } Driver Code Ends