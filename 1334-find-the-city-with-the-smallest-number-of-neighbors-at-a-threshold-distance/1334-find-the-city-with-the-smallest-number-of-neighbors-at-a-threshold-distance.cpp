class Solution {
public:
    #define P pair<int, int>
    void dijkstra(int n, unordered_map<int, vector<P>> &mp, vector<int> &result, int s) {
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, s});
        //fill(result.begin(), result.end(), INT_MAX);
        result[s] = 0;
        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto &nei : mp[node]) {
                int adjNode = nei.first;
                int dist = nei.second;
                if (d + dist < result[adjNode]) {
                    result[adjNode] = d + dist;
                    pq.push({d+dist, adjNode});
                }
            }
        }
    }
    int findResultCity(int n, vector<vector<int>> &spm, int d) {
        int resultCity = -1;
        int leastReachCount = INT_MAX;
        for (int i = 0; i < n; i++) {
            int countReach = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && spm[i][j] <= d) {
                    countReach++;
                }
            }
            if (countReach <= leastReachCount) {
                leastReachCount = countReach;
                resultCity = i;
            }
        }
        return resultCity;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> spm(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++) {
            spm[i][i] = 0;
        }
        unordered_map<int, vector<P>> mp;
        for (auto &x : edges) {
            int u = x[0];
            int v = x[1];
            int w = x[2];
            mp[u].push_back({v, w});
            mp[v].push_back({u, w});
        }
        for (int i = 0; i < n; i++) {
            dijkstra(n, mp, spm[i], i);
        }
        return findResultCity(n, spm, distanceThreshold);
    }
};