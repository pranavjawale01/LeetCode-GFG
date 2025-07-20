class Solution {
public:
    #define P pair<int, int>
    void floydWarshall(int n, vector<vector<int>>& spm) {
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (spm[i][via] < INT_MAX && spm[via][j] < INT_MAX) {
                        spm[i][j] = min(spm[i][j], spm[i][via] + spm[via][j]);
                    }
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
        for (auto &x : edges) {
            int u = x[0];
            int v = x[1];
            int w = x[2];
            spm[u][v] = w;
            spm[v][u] = w;
        }
        floydWarshall(n, spm);
        return findResultCity(n, spm, distanceThreshold);
    }
};










// class Solution {
// public:
//     #define P pair<int, int>
//     void bellmanFord(int n, vector<vector<int>>& edges, vector<int> &result, int s) {
//         result[s] = 0;
//         for (int i = 1; i < n; i++) {
//             for (auto &x : edges) {
//                 int u = x[0];
//                 int v = x[1];
//                 int w = x[2];
//                 if (result[u] != INT_MAX && result[u] + w < result[v]) {
//                     result[v] = result[u] + w;
//                 }
//                 if (result[v] != INT_MAX && result[v] + w < result[u]) {
//                     result[u] = result[v] + w;
//                 }
//             }
//         }
//     }
//     int findResultCity(int n, vector<vector<int>> &spm, int d) {
//         int resultCity = -1;
//         int leastReachCount = INT_MAX;
//         for (int i = 0; i < n; i++) {
//             int countReach = 0;
//             for (int j = 0; j < n; j++) {
//                 if (i != j && spm[i][j] <= d) {
//                     countReach++;
//                 }
//             }
//             if (countReach <= leastReachCount) {
//                 leastReachCount = countReach;
//                 resultCity = i;
//             }
//         }
//         return resultCity;
//     }
//     int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
//         vector<vector<int>> spm(n, vector<int>(n, INT_MAX));
//         for (int i = 0; i < n; i++) {
//             spm[i][i] = 0;
//         }
//         for (auto &x : edges) {
//             int u = x[0];
//             int v = x[1];
//             int w = x[2];
//             spm[u][v] = w;
//             spm[v][u] = w;
//         }
//         for (int i = 0; i < n; i++) {
//             bellmanFord(n, edges, spm[i], i);
//         }
//         return findResultCity(n, spm, distanceThreshold);
//     }
// };














// class Solution {
// public:
//     #define P pair<int, int>
//     void dijkstra(int n, unordered_map<int, vector<P>> &mp, vector<int> &result, int s) {
//         priority_queue<P, vector<P>, greater<P>> pq;
//         pq.push({0, s});
//         //fill(result.begin(), result.end(), INT_MAX);
//         result[s] = 0;
//         while (!pq.empty()) {
//             int d = pq.top().first;
//             int node = pq.top().second;
//             pq.pop();
//             for (auto &nei : mp[node]) {
//                 int adjNode = nei.first;
//                 int dist = nei.second;
//                 if (d + dist < result[adjNode]) {
//                     result[adjNode] = d + dist;
//                     pq.push({d+dist, adjNode});
//                 }
//             }
//         }
//     }
//     int findResultCity(int n, vector<vector<int>> &spm, int d) {
//         int resultCity = -1;
//         int leastReachCount = INT_MAX;
//         for (int i = 0; i < n; i++) {
//             int countReach = 0;
//             for (int j = 0; j < n; j++) {
//                 if (i != j && spm[i][j] <= d) {
//                     countReach++;
//                 }
//             }
//             if (countReach <= leastReachCount) {
//                 leastReachCount = countReach;
//                 resultCity = i;
//             }
//         }
//         return resultCity;
//     }
//     int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
//         vector<vector<int>> spm(n, vector<int>(n, INT_MAX));
//         for (int i = 0; i < n; i++) {
//             spm[i][i] = 0;
//         }
//         unordered_map<int, vector<P>> mp;
//         for (auto &x : edges) {
//             int u = x[0];
//             int v = x[1];
//             int w = x[2];
//             mp[u].push_back({v, w});
//             mp[v].push_back({u, w});
//         }
//         for (int i = 0; i < n; i++) {
//             dijkstra(n, mp, spm[i], i);
//         }
//         return findResultCity(n, spm, distanceThreshold);
//     }
// };