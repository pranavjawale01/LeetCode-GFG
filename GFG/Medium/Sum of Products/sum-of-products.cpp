//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    long long pairAndSum(int n, long long arr[]) {
        // code here
        vector<long long> freq(32, 0);
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long curr = arr[i];
            for (int j = 0; j < 32; j++) {
                if ((curr >> j) & 1) {
                    ans += (freq[j]*1ll*(1ll<<j));
                    freq[j]++;
                }
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
        int N;
        cin >> N;
        long long Arr[N];
        for (int i = 0; i < N; i++) {
            cin >> Arr[i];
        }
        Solution ob;
        cout << ob.pairAndSum(N, Arr) << endl;
    }
    return 0;
}
// } Driver Code Ends