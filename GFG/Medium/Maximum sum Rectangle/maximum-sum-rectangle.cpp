//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int kadaneAlgo(int nums[], int n) {
        int currSum = nums[0];
        int maxSum  = nums[0];
        for (int i = 1; i < n; i++) {
            currSum = max(currSum + nums[i], nums[i]);
            maxSum  = max(maxSum, currSum);
        }
        return maxSum;
    }

    int maximumSumRectangle(int R, int C, vector<vector<int>>& M) {
        int maxSum = INT_MIN;
        for (int cStart = 0; cStart < C; cStart++) {
            int sum[R] = {0};
            for (int cEnd = cStart; cEnd < C; cEnd++) {
                for (int row = 0; row < R; row++) {
                    sum[row] += M[row][cEnd];
                }
                int curMaxSum = kadaneAlgo(sum, R);
                maxSum = max(maxSum, curMaxSum);
            }
        }
        return maxSum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}
// } Driver Code Ends