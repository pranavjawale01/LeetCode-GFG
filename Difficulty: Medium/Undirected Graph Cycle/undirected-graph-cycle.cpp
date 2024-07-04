//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    bool isCycleBFS(vector<int> g[], int V, int start, vector<bool>& visited) {
        queue<pair<int, int>> que;
        que.push({start, -1});
        visited[start] = true;
        while(!que.empty()) {
            int curr   = que.front().first;
            int parent = que.front().second;
            que.pop();
            
            for(auto x : g[curr]) {
                if(visited[x] == false) {
                    que.push({x, curr});
                    visited[x] = true;
                }
                else if(x != parent)
                    return true;
            }
        }
        
        return false;
    }

  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        
        vector<bool> visited(V, false);
        
        for(int i = 0; i<V; i++) {
            if(!visited[i] && isCycleBFS(adj, V, i, visited)) {
                return true;
            }
        }
        
        return false;
        
    }
};






// class Solution {
//   public:
//     // Function to detect cycle in an undirected graph.
//     bool dfs(int v, int parent, vector<int> adj[], vector<bool>& visited) {
//         visited[v] = true;

//         for (int u : adj[v]) {
//             if (!visited[u]) {
//                 if (dfs(u, v, adj, visited)) {
//                     return true;
//                 }
//             } else if (u != parent) {
//                 return true;
//             }
//         }

//         return false;
//     }

//     bool isCycle(int V, vector<int> adj[]) {
//         vector<bool> visited(V, false);

//         for (int i = 0; i < V; i++) {
//             if (!visited[i]) {
//                 if (dfs(i, -1, adj, visited)) {
//                     return true;
//                 }
//             }
//         }

//         return false;
//     }
// };


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends