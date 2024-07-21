class Solution {
public:
    vector<int> topoSort(vector<vector<int>>& edges, int n) {
        vector<vector<int>> adj(n + 1);
        vector<int> indegree(n + 1);
        vector<int> order;
        for (vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int> que;
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                que.push(i);
                count++;
            }
        }
 
        while(!que.empty()) {
	        int u = que.front();
	        order.push_back(u);
	        que.pop();
	        
	        for(int &v : adj[u]) {
	            indegree[v]--;
	            
	            if(indegree[v] == 0) {
	                que.push(v);
                    count++;
	            }
	            
	        }
	    }

        if (count != n) 
            return {}; 
        return order;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> orderRows    = topoSort(rowConditions, k);
        vector<int> orderColumns = topoSort(colConditions, k);

        if (orderRows.empty() or orderColumns.empty())
            return {};

        vector<vector<int>> matrix(k, vector<int>(k, 0));
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (orderRows[i] == orderColumns[j]) {
                    matrix[i][j] = orderRows[i];
                }
            }
        }
        return matrix;
    }
};






// class Solution {
// public:
//     void dfs(int node, unordered_map<int, vector<int>> &adj, vector<int> &vis, stack<int> &st, bool &hasCycle) {
//         vis[node] = 1;
//         for (int &x : adj[node]) {
//             if (vis[x] == 0) {
//                 dfs(x, adj, vis, st, hasCycle);
//             } else if (vis[x] == 1) {
//                 hasCycle = true;
//                 return;
//             }
//         }
//         vis[node] = 2;
//         st.push(node);
//     }
//     vector<int> topoSort(vector<vector<int>> &edges, int n) {
//         unordered_map<int, vector<int>> adj;
//         stack<int> st;
//         vector<int> order;
//         vector<int> vis(n+1, 0);
//         bool hasCycle = false;
//         for (vector<int> &edge : edges) {
//             int u = edge[0];
//             int v = edge[1];
//             adj[u].push_back(v);
//         }
//         for (int i = 1; i <= n; i++) {
//             if (vis[i] == 0) {
//                 dfs(i, adj, vis, st, hasCycle);
//                 if (hasCycle) {
//                     return {};
//                 }
//             }
//         }
//         while (!st.empty()) {
//             order.push_back(st.top());
//             st.pop();
//         }
//         return order;
//     }
//     vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
//         vector<int> orderRows = topoSort(rowConditions, k);
//         vector<int> orderCols = topoSort(colConditions, k);

//         if (orderRows.empty() || orderCols.empty()) {
//             return {};
//         }

//         vector<vector<int>> matrix(k, vector<int>(k, 0));

//         for (int i = 0; i < k; i++) {
//             for (int j = 0; j < k; j++) {
//                 if (orderRows[i] == orderCols[j]) {
//                     matrix[i][j] = orderRows[i];
//                 }
//             }
//         }

//         return matrix;
//     }
// };