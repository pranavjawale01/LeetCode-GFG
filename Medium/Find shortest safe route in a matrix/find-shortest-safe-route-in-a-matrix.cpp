//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    int findShortestPath(vector<vector<int>> &mat)
    {
       // code here
       int r = mat.size(), c = mat[0].size();
       vector<vector<int>> arr(r,vector<int>(c,1));
       int direRow[]={-1,0,1,0};
       int direCol[]={0,1,0,-1};
       for(int i=0;i<r;i++){
           for(int j=0;j<c;j++){
               if(mat[i][j]==0){
                   arr[i][j]=0;
                   for(int k=0;k<4;k++){
                       int nr = direRow[k]+i;
                       int nc = direCol[k]+j;
                       if(nr>=0 and nr<r and nc>=0 and nc<c){
                           arr[nr][nc]=0;
                       }
                   }
               }
           }
       }
       vector<vector<int>> vis(r,vector<int>(c,0));
       queue<pair<int,pair<int,int>>> q;
       for(int i=0;i<r;i++){
           if(arr[i][0])q.push({1,{i,0}});
       }
       while(q.size()){
           auto temp = q.front();
           q.pop();
           int i = temp.second.first;
           int j = temp.second.second;
           int dis = temp.first;
           if(j==c-1)return dis;
           vis[i][j]=1;
           for(int k=0;k<4;k++){
               int nr = direRow[k]+i;
               int nc = direCol[k]+j;
               if(nr>=0 and nr<r and nc>=0 and nc<c and vis[nr][nc]==0 and arr[nr][nc]==1){
                   q.push({dis+1,{nr,nc}});
               }
           }
       }
       return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends