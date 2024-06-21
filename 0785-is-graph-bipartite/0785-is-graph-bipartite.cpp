class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int> &color, int node, int col) {
        if (color[node] != 0) {
            return (color[node] == col);
        }
        color[node] = col;
        for (int ne : graph[node]) {
            if (!dfs(graph, color, ne, -col)) {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);
        for (int i = 0; i < n; i++) {
            if (color[i] == 0 && !dfs(graph, color, i, 1)) {
                return false;
            } 
        }
        return true;
    }
};