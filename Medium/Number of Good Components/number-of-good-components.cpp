//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
public:
    bool bfs(int node, vector<bool> &vis, map<int, vector<int>> &mp) {
        int num = 0, edges = 0;
        queue<int> q;
        q.push(node);
        vis[node] = true;
        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            num++;
            edges += mp[temp].size();
            for (auto it : mp[temp]) {
                if (!vis[it]) {
                    q.push(it);
                    vis[it] = true;
                }
            }
        }
        return num * (num - 1) == edges;
    }

    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        map<int, vector<int>> mp;
        for (vector<int>& edge : edges) {
            mp[edge[0]].push_back(edge[1]);
            mp[edge[1]].push_back(edge[0]);
        }
        int ans = 0;
        vector<bool> vis(v + 1, false);
        for (int i = 1; i <= v; i++) {
            if (!vis[i] && bfs(i, vis, mp)) {
                ans++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        int res = obj.findNumberOfGoodComponent(e, v, edges);

        cout << res << endl;
    }
}

// } Driver Code Ends