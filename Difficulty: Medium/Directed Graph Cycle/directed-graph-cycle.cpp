//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCycleDFS(vector<int> adj[], int u, vector<bool> &vis, vector<bool> &rec) {
        vis[u] = true;
        rec[u] = true;
        for (int &v : adj[u]) {
            if (vis[v] == false && isCycleDFS(adj, v, vis, rec)) {
                return true;
            } else if (rec[v]) {
                return true;
            }
        }
        rec[u] = false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> vis(V, false);
        vector<bool> rec(V, false);
        for (int i = 0; i < V; i++) {
            if (!vis[i] && isCycleDFS(adj, i, vis, rec)) {
                return true;
            }
        }
        return false;
    }
};




// class Solution {
// public:
//     bool isCyclic(int V, vector<int> adj[]) {
//         vector<int> indegree(V, 0);
//         for (int i = 0; i < V; ++i) {
//             for (auto x : adj[i]) {
//                 indegree[x]++;
//             }
//         }

//         queue<int> q;
//         for (int i = 0; i < V; ++i) {
//             if (indegree[i] == 0) {
//                 q.push(i);
//             }
//         }

//         int visited = 0;
//         while (!q.empty()) {
//             int u = q.front();
//             q.pop();
//             visited++;
//             for (auto v : adj[u]) {
//                 indegree[v]--;
//                 if (indegree[v] == 0) {
//                     q.push(v);
//                 }
//             }
//         }

//         return visited != V;
//     }
// };

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends