//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int dfs(int node, int d, vector<vector<int>>& adjList, vector<bool>& visited) {
        if (node == d) return 1;
        
        visited[node] = true;
        int pathCount = 0;
        
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                pathCount += dfs(neighbor, d, adjList, visited);
            }
        }
        
        visited[node] = false;
        return pathCount;
    }
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    // Code here
	    vector<vector<int>> adjList(n);
        for (const auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
        }
        
        vector<bool> visited(n, false);
        
        return dfs(s, d, adjList, visited);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends