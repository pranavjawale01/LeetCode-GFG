class Solution {
public:
    bool isCycleDFS(vector<vector<int>>& graph, int u, vector<bool> &visited, vector<bool> &inRecursion) {
        visited[u] = true;
        inRecursion[u] = true;
        for (int &v : graph[u]) {
            if (visited[v] == false && isCycleDFS(graph, v, visited, inRecursion)) {
                return true;
            } else if (inRecursion[v] == true) {
                return true;
            }
        }
        inRecursion[u] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<bool> visited(V, false);
        vector<bool> inRecursion(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                isCycleDFS(graph, i, visited, inRecursion);
            }
        }
        vector<int> safeNodes;
        for (int i = 0; i < V; i++) {
            if (!inRecursion[i]) {
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};