//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    long long getCount(int n) {
        if (n == 1) {
            return 10;
        }

        unordered_map<int, vector<int>> mp;
        mp[0] = {0, 8};
        mp[1] = {1, 2, 4};
        mp[2] = {2, 1, 3, 5};
        mp[3] = {3, 2, 6};
        mp[4] = {4, 1, 5, 7};
        mp[5] = {5, 2, 4, 6, 8};
        mp[6] = {6, 3, 5, 9};
        mp[7] = {7, 4, 8};
        mp[8] = {8, 5, 7, 9, 0};
        mp[9] = {9, 6, 8};

        vector<vector<long long>> dp(n + 1, vector<long long>(10, 0));
        for (int i = 0; i < 10; i++) {
            dp[1][i] = 1;
        }
        
        for (int len = 2; len <= n; len++) {
            for (int digit = 0; digit < 10; digit++) {
                dp[len][digit] = 0;
                for (int x : mp[digit]) {
                    dp[len][digit] += dp[len - 1][x];
                }
            }
        }
        
        long long ans = 0;
        for (int i = 0; i < 10; i++) {
            ans += dp[n][i];
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

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends