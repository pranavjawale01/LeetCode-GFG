class Solution {
public:
    const int INF = 2e9;

    int dijkstra(int n, int src, int dest, vector<vector<pair<int, int>>> &adj) {
        vector<int> dist(n, INF);
        dist[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u]) {
                continue;
            }
            for (auto [v, w] : adj[u]) {
                if (w + d < dist[v]) {
                    dist[v] = w + d;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist[dest];
    }

    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto x : edges) {
            int a = x[0], b = x[1], c = x[2];
            if (c != -1) {
                adj[a].push_back({b, c});
                adj[b].push_back({a, c});
            }
        }
        
        int initialDist = dijkstra(n, source, destination, adj);
        if (initialDist < target) {
            return {};
        }
        
        bool flag = target == initialDist;
        for (auto &x : edges) {
            int a = x[0], b = x[1], &c = x[2];
            if (c == -1) {
                c = flag ? INF : 1;
                if (!flag) {
                    adj[a].push_back({b, c});
                    adj[b].push_back({a, c});
                    int newShortDist = dijkstra(n, source, destination, adj);
                    if (newShortDist <= target) {
                        flag = true;
                        c += target - newShortDist;
                    }
                }
            }
        }
        
        if (!flag) {
            return {};
        }
        return edges;
    }
};