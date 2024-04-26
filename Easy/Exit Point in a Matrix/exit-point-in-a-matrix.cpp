//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        // Code here
        int i = 0, j = 0, previ = 0, prevj = 0, dir = 0;
        while (i < n && i >= 0 && j < m && j >= 0) {
            previ = i;
            prevj = j;
            if (matrix[i][j] == 1) {
                matrix[i][j] = 0;
                if (dir == 0) {
                    i++;
                    dir = 1;
                } else if (dir == 1) {
                    j--;
                    dir = 2;
                } else if (dir == 2) {
                    i--;
                    dir = 3;
                } else if (dir == 3) {
                    j++;
                    dir = 0;
                }
            } else {
                if (dir == 0) {
                    j++;
                } else if (dir == 1) {
                    i++;
                } else if (dir == 2) {
                    j--;
                } else if (dir == 3) {
                    i--;
                }
            }
        }
        return {previ, prevj};
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends