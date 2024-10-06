//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int row, col;

    void solve(int i, int j, vector<vector<char>>& grid) {
        if (i < 0 || j < 0 || i >= row || j >= col || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        solve(i + 1, j, grid);
        solve(i, j + 1, grid);
        solve(i - 1, j, grid);
        solve(i, j - 1, grid);
        solve(i - 1, j - 1, grid);
        solve(i + 1, j - 1, grid);
        solve(i + 1, j + 1, grid);
        solve(i - 1, j + 1, grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int count = 0;
        row = grid.size();
        col = grid[0].size();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    solve(i, j, grid);
                }
            }
        }
        return count;
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends