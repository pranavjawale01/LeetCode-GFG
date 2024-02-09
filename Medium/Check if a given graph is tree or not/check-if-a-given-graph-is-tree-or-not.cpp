//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends
class Solution {
  public:
    bool isCycle(vector<vector<int>>& mapList, vector<int>& visited, int n, int m, int node, int parent) {
        visited[node] = 1;
        for (auto newNode : mapList[node]) {
            if (!visited[newNode]) {
                if (!isCycle(mapList, visited, n, m, newNode, node)) {
                    return false;
                }
            } else if (newNode != parent) {
                return false;
            }
        }
        return true;
    }
    
    int isTree(int n, int m, vector<vector<int>> &adj) {
        vector<vector<int>> mapList(n, vector<int>());
        for (int i = 0; i < m; i++) {
            mapList[adj[i][0]].push_back(adj[i][1]);
            mapList[adj[i][1]].push_back(adj[i][0]);
        }
        vector<int> visited(n, 0);
        bool result = isCycle(mapList, visited, n, m, 0, -1);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                return 0;
            }
        }
        return result;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> edges(m, vector<int>(2));
        Matrix::input(edges,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, edges);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends