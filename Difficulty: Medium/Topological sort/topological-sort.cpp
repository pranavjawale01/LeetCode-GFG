//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> indegree(V, 0);
	    for (int u = 0; u < V; ++u) {
            for (int v : adj[u]) {
                indegree[v]++;
            }
        }
        
        queue<int> q;
        for (int i = 0; i < V; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> ans;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ans.push_back(u);
            
            for (int v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        if (ans.size() != V) {
            return {};
        }
        
        return ans;
	}
};






// class Solution
// {
// 	public:
// 	//Function to return list containing vertices in Topological order.
	
// 	void dfs(vector<int> adj[], int u, vector<bool> &vis, stack<int> &st) {
// 	    vis[u] = true;
// 	    for (int &v : adj[u]) {
// 	        if (!vis[v]) {
// 	            dfs(adj, v, vis, st);
// 	        }
// 	    }
// 	    st.push(u);
// 	}
	
// 	vector<int> topoSort(int V, vector<int> adj[]) 
// 	{
// 	    // code here
// 	    vector<bool> vis(V, false);
// 	    stack<int> st;
// 	    for (int i = 0; i < V; i++) {
// 	        if (!vis[i]) {
// 	            dfs(adj, i, vis, st);
// 	        }
// 	    }
// 	    vector<int> ans;
// 	    while (!st.empty()) {
// 	        ans.push_back(st.top());
// 	        st.pop();
// 	    }
// 	    return ans;
// 	}
// };


//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends