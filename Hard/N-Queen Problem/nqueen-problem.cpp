//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void solveNQueens(int row, int n, vector<int>& board, vector<vector<int>>& results) {
        if (row == n) {
            results.push_back(board);
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (isValid(row, col, board)) {
                board[row] = col + 1;
                solveNQueens(row + 1, n, board, results);
                board[row] = 0;
            }
        }
    }
    
    bool isValid(int row, int col, const vector<int>& board) {
        for (int i = 0; i < row; i++) {
            if (board[i] == col + 1 || abs(board[i] - (col + 1)) == abs(i - row)) {
                return false;
            }
        }
        return true;
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> results;
        vector<int> board(n);
        solveNQueens(0, n, board, results);
        return results;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends