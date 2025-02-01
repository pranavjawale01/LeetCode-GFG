//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        // Code here
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        function<bool(int, int, int)> solve = [&](int i, int j, int idx) {
            if (idx == word.size()) {
                return true;
            }
            char temp = mat[i][j];
            mat[i][j] = '#';
            for (auto &d : dirs) {
                int x = d[0] + i;
                int y = d[1] + j;
                if (x >= 0 && x < n && y >= 0 && y < m && mat[x][y] == word[idx]) {
                    if (solve(x, y, idx + 1)) {
                        return true;
                    }
                }
            }
            mat[i][j] = temp;
            return false;
        };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == word[0] && solve(i, j, 1)) {
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends