class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);

        for (int node = 0; node < n; node++) {
            if (color[node] != 0) {
                continue;
            }
            queue<int> q;
            q.push(node);
            color[node] = 1;

            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                for (int ne : graph[cur]) {
                    if (color[ne] == 0) {
                        color[ne] = -color[cur];
                        q.push(ne);
                    } else if (color[ne] != -color[cur]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};



// class Solution {
// public:
//     bool dfs(vector<vector<int>>& graph, vector<int> &color, int node, int col) {
//         if (color[node] != 0) {
//             return (color[node] == col);
//         }
//         color[node] = col;
//         for (int ne : graph[node]) {
//             if (!dfs(graph, color, ne, -col)) {
//                 return false;
//             }
//         }
//         return true;
//     }
//     bool isBipartite(vector<vector<int>>& graph) {
//         int n = graph.size();
//         vector<int> color(n, 0);
//         for (int i = 0; i < n; i++) {
//             if (color[i] == 0 && !dfs(graph, color, i, 1)) {
//                 return false;
//             } 
//         }
//         return true;
//     }
// };