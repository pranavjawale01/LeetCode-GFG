//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    void dfs(vector<vector<int>>& matrix, int x, int y, int N, int M) {
        if (x < 0 || x >= N || y < 0 || y >= M || matrix[x][y] == 0) {
            return;
        }
        
        matrix[x][y] = 0;
        
        dfs(matrix, x + 1, y, N, M);
        dfs(matrix, x - 1, y, N, M);
        dfs(matrix, x, y + 1, N, M);
        dfs(matrix, x, y - 1, N, M);
    }
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        // Code here
        for (int i = 0; i < N; i++) {
            if (matrix[i][0] == 1) dfs(matrix, i, 0, N, M);
            if (matrix[i][M-1] == 1) dfs(matrix, i, M-1, N, M);
        }
        for (int j = 0; j < M; j++) {
            if (matrix[0][j] == 1) dfs(matrix, 0, j, N, M);
            if (matrix[N-1][j] == 1) dfs(matrix, N-1, j, N, M);
        }

        int count = 0;
        for (int i = 1; i < N-1; i++) {
            for (int j = 1; j < M-1; j++) {
                if (matrix[i][j] == 1) {
                    dfs(matrix, i, j, N, M);
                    count++;
                }
            }
        }

        return count;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends