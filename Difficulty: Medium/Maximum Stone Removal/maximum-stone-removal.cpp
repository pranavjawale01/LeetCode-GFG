//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> parent, rank;
    
    int find(int i) {
        if (i != parent[i]) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }
    
    void Union(int u, int v) {
        int par_u = find(u);
        int par_v = find(v);
        if (par_u != par_v) {
            if (rank[par_u] > rank[par_v]) {
                parent[par_v] = par_u;
            } else if (rank[par_u] < rank[par_v]) {
                parent[par_u] = par_v;
            } else {
                parent[par_v] = par_u;
            }
        }
    }
    
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here
        parent.resize(n, 0);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    Union(i, j);
                }
            }
        }
        int group = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i) {
                group++;
            }
        }
        return n - group;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends