//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
  public:
    int minDist(int a[], int n, int x, int y) {
        // code here
        int minDistance = INT_MAX;
        int lastIndexX = -1, lastIndexY = -1;
    
        for (int i = 0; i < n; ++i) {
            if (a[i] == x) {
                if (lastIndexY != -1) {
                    minDistance = min(minDistance, i - lastIndexY);
                }
                lastIndexX = i;
            } else if (a[i] == y) {
                if (lastIndexX != -1) {
                    minDistance = min(minDistance, i - lastIndexX);
                }
                lastIndexY = i;
            }
        }
    
        if (minDistance == INT_MAX) {
            return -1;
        } else {
            return minDistance;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}

// } Driver Code Ends