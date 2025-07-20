class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> mp;
        for (auto &x : times) {
            int u = x[0];
            int v = x[1];
            int w = x[2];
            mp[u].push_back({v, w});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> result(n+1, INT_MAX);
        result[k] = 0;
        pq.push({0, k});
        
        while (!pq.empty()) {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if (dist > result[node]) continue;
            
            for (auto &x : mp[node]) {
                int adjNode = x.first;
                int d       = x.second;
                if (d + dist < result[adjNode]) {
                    result[adjNode] = d + dist;
                    pq.push({d+dist, adjNode});
                }
            }
        }
        
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (result[i] == INT_MAX) return -1;
            ans = max(ans, result[i]);
        }
        
        return ans;
    }
};