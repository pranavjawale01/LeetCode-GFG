//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isSafe(int node, vector<int>& color, vector<vector<int>>& adj, int col) {
        for (int neighbor : adj[node]) {
            if (color[neighbor] == col) {
                return false;
            }
        }
        return true;
    }

    bool backtrack(int node, int v, vector<int>& color, vector<vector<int>>& adj, int m) {
        if (node == v) return true;

        for (int col = 1; col <= m; col++) {
            if (isSafe(node, color, adj, col)) {
                color[node] = col;
                if (backtrack(node + 1, v, color, adj, m)) {
                    return true;
                }
                color[node] = 0;
            }
        }
        return false;
    }

    bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
        vector<vector<int>> adj(v);
        for (auto& edge : edges) {
            adj[edge.first].push_back(edge.second);
            adj[edge.second].push_back(edge.first);
        }

        vector<int> color(v, 0);
        return backtrack(0, v, color, adj, m);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m;
        cin >> n;
        cin.ignore(); // Ignore newline after reading n
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number); // Populate the array with edge values
        }
        cin >> m;
        cin.ignore(); // Ignore newline after reading m

        int edges_count = arr.size();
        vector<pair<int, int>> edges(edges_count /
                                     2); // Correct size of the edges vector

        for (int i = 0; i < edges_count; i += 2) {
            int l1 = arr[i];
            int l2 = arr[i + 1];
            edges[i / 2] = {l1, l2}; // Properly assign the pair
        }

        Solution ob;
        cout << (ob.graphColoring(n, edges, m) ? "true" : "false")
             << "\n~\n"; // Call the graph coloring function
    }
    return 0;
}

// } Driver Code Ends