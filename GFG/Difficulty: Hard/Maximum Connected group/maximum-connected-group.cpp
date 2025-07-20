//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int n;
    int dfs(vector<vector<int>> &grid, int i, int j, int area) {
        if (i < 0 || j < 0 || i >= n || j >= n || grid[i][j] != 1) {
            return 0;
        }
        grid[i][j] = area;
        int a = dfs(grid, i+1, j, area);
        int b = dfs(grid, i, j+1, area);
        int c = dfs(grid, i-1, j, area);
        int d = dfs(grid, i, j-1, area);
        return 1 + a + b + c + d;
    }
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int ans = 0;
        n = grid.size();
        map<int, int> mp;
        int area = 2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    mp[area] = dfs(grid, i, j, area);
                    ans = max(ans, mp[area]);
                    area++;
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    set<int> st;
                    int maxarea = 1;
                    if (i > 0) {
                        st.insert(grid[i-1][j]);
                    }
                    if (j > 0) {
                        st.insert(grid[i][j-1]);
                    }
                    if (i < n - 1) {
                        st.insert(grid[i+1][j]);
                    }
                    if (j < n - 1) {
                        st.insert(grid[i][j+1]);
                    }
                    for (int x : st) {
                        maxarea += mp[x];
                    }
                    ans = max(ans, maxarea);
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
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
    }
}

// } Driver Code Ends