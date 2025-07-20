//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int row = mat.size(), col = mat[0].size();
        int ans = -1;
        for (int i = 0; i < row; i++) {
            bool flag = true;
            for (int j = 0; j < col; j++) {
                if (mat[i][j] == 1) {
                    flag = false;
                }
            }
            if (flag) {
                if (ans != -1) {
                    return -1;
                }
                ans = i;
            }
            if (ans != -1) {
                for (int j = 0; j < row; j++) {
                    if (ans == j) {
                        continue;
                    }
                    if (mat[j][ans] == 0) {
                        return -1;
                    }
                }
                return ans;
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
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends