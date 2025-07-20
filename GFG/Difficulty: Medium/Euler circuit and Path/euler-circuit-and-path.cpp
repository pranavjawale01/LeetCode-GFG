//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(vector<int> adj[], int u,  vector<bool> &vis) {
        vis[u] = true;
        for (auto it = adj[u].begin(); it != adj[u].end(); it++) {
            int nei = *it;
            if (!vis[nei]) {
                dfs(adj, nei, vis);
            }
        } 
    }
    bool isConnected(int V, vector<int> adj[]) {
        int nonZeroDegreeVertex = -1;
        for (int i = 0; i < V; i++) {
            if (adj[i].size() != 0) {
                nonZeroDegreeVertex = i;
                break;
            }
        }
        vector<bool> vis(V, false);
        dfs(adj, nonZeroDegreeVertex, vis);
        for (int i = 0; i < V; i++) {
            if (!vis[i] && adj[i].size() > 0) {
                return false;
            }
        }
        return true;
    }
	int isEulerCircuit(int V, vector<int>adj[]){
	    // Code here
	    if (isConnected(V, adj) == false) {
	        return 0;
	    }
	    
	    int oddDegreeCount = 0;
	    for (int i = 0; i < V; i++) {
	        if (adj[i].size() % 2 != 0) {
	            oddDegreeCount++;
	        }
	    }
	    if (oddDegreeCount > 2) {
	        return 0;
	    }
	    if (oddDegreeCount == 2) {
	        return 1;
	    }
	    return 2;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.isEulerCircuit(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends