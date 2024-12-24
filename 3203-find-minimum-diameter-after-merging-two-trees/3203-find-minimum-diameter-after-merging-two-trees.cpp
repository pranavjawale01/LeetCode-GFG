class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        auto computeDiameter = [](unordered_map<int, vector<int>>& adj) -> int {
            auto bfs = [&](int start) {
                unordered_map<int, int> dist;
                queue<int> q;
                q.push(start);
                dist[start] = 0;
                int farthest = start;
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    for (auto& neighbor : adj[node]) {
                        if (dist.find(neighbor) == dist.end()) {
                            dist[neighbor] = dist[node] + 1;
                            q.push(neighbor);
                            if (dist[neighbor] > dist[farthest]) farthest = neighbor;
                        }
                    }
                }
                return make_pair(farthest, dist[farthest]);
            };
            auto [startNode, _] = bfs(0);
            auto [farthestNode, diameter] = bfs(startNode);
            return diameter;
        };

        unordered_map<int, vector<int>> mp1, mp2;
        for (auto& edge : edges1) {
            mp1[edge[0]].push_back(edge[1]);
            mp1[edge[1]].push_back(edge[0]);
        }
        for (auto& edge : edges2) {
            mp2[edge[0]].push_back(edge[1]);
            mp2[edge[1]].push_back(edge[0]);
        }
        int d1 = computeDiameter(mp1);
        int d2 = computeDiameter(mp2);
        return max({d1, d2, (d1 + 1 + d2 + 1 + 1) / 2});
    }
};
