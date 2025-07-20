class Solution {
public:
    typedef pair<double, int> p;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, vector<pair<int, double>>> adj;
        vector<double> result(n, 0);
        int i = 0;
        for (auto x : edges) {
            int u = x[0];
            int v = x[1];
            double prob = succProb[i];
            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
            i++;
        }
        priority_queue<p> pq;
        result[start_node] = 1;
        pq.push({1.0, start_node});
        while (!pq.empty()) {
            int curr_node = pq.top().second;
            double curr_prob = pq.top().first;
            pq.pop();
            for (auto &x : adj[curr_node]) {
                if (result[x.first] < curr_prob * x.second) {
                    result[x.first] = curr_prob * x.second;
                    pq.push({result[x.first], x.first});
                }
            }
        }
        return result[end_node];
    }
};