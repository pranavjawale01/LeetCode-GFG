class Solution {
public:
    void dijkstra(char s, unordered_map<char, vector<pair<char, int>>> &adj, vector<vector<long long>> &arr) {
        priority_queue<pair<long long, char>, vector<pair<long long, char>>, greater<pair<long long, char>>> pq;
        vector<long long> dist(26, LLONG_MAX);
        dist[s - 'a'] = 0;
        pq.push({0, s});
        
        while (!pq.empty()) {
            long long d = pq.top().first;
            char n = pq.top().second;
            pq.pop();
            
            if (d > dist[n - 'a']) continue;

            for (auto &x : adj[n]) {
                char node = x.first;
                int cost = x.second;
                if (dist[node - 'a'] > d + cost) {
                    dist[node - 'a'] = d + cost;
                    pq.push({d + cost, node});
                }
            }
        }

        for (int i = 0; i < 26; i++) {
            arr[s - 'a'][i] = dist[i];
        }
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_map<char, vector<pair<char, int>>> adj;
        for (int i = 0; i < original.size(); i++) {
            adj[original[i]].push_back({changed[i], cost[i]});
        }

        vector<vector<long long>> arr(26, vector<long long>(26, LLONG_MAX));

        for (char c = 'a'; c <= 'z'; c++) {
            dijkstra(c, adj, arr);
        }

        long long ans = 0;
        int n = source.size();

        for (int i = 0; i < n; i++) {
            int u = source[i] - 'a';
            int v = target[i] - 'a';
            if (arr[u][v] == LLONG_MAX) {
                return -1;
            }
            ans += arr[u][v];
        }
        return ans;
    }
};









// class Solution {
// public:
//     void bellmanFord(vector<vector<long long>> &arr, int s) {
//         int V = arr.size();
//         vector<long long> dist(V, INT_MAX);
//         dist[s] = 0;

//         for (int i = 0; i < V - 1; i++) {
//             for (int u = 0; u < V; u++) {
//                 for (int v = 0; v < V; v++) {
//                     if (dist[u] != INT_MAX && dist[u] + arr[u][v] < dist[v]) {
//                         dist[v] = dist[u] + arr[u][v];
//                     }
//                 }
//             }
//         }

//         for (int i = 0; i < V; i++) {
//             arr[s][i] = dist[i];
//         }
//     }

//     long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
//         vector<vector<long long>> arr(26, vector<long long>(26, INT_MAX));
//         int n = original.size();

//         for (int i = 0; i < n; i++) {
//             int u = original[i] - 'a';
//             int v = changed[i] - 'a';
//             arr[u][v] = min((long long)cost[i], arr[u][v]);
//         }

//         for (int i = 0; i < 26; i++) {
//             arr[i][i] = 0;
//         }

//         for (int i = 0; i < 26; i++) {
//             bellmanFord(arr, i);
//         }

//         long long ans = 0;
//         n = source.size();

//         for (int i = 0; i < n; i++) {
//             int u = source[i] - 'a';
//             int v = target[i] - 'a';
//             if (arr[u][v] == INT_MAX) {
//                 return -1;
//             }
//             ans += arr[u][v];
//         }
//         return ans;
//     }
// };










// class Solution {
// public:
//     void floydWarshall(vector<vector<long long>> &arr) {
//         for (int via = 0; via < 26; via++) {
//             for (int i = 0; i < 26; i++) {
//                 for (int j = 0; j < 26; j++) {
//                     if (arr[i][via] < INT_MAX && arr[via][j] < INT_MAX) {
//                         arr[i][j] = min(arr[i][j], arr[i][via] + arr[via][j]);
//                     }
//                 }
//             }
//         }
//     }

//     long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
//         vector<vector<long long>> arr(26, vector<long long>(26, INT_MAX));
//         int n = original.size();
        
//         for (int i = 0; i < n; i++) {
//             int u = original[i] - 'a';
//             int v = changed[i] - 'a';
//             arr[u][v] = min((long long)cost[i], arr[u][v]);
//         }
        
//         for (int i = 0; i < 26; i++) {
//             arr[i][i] = 0;
//         }
        
//         floydWarshall(arr);
        
//         long long ans = 0;
//         n = source.size();
        
//         for (int i = 0; i < n; i++) {
//             int u = source[i] - 'a';
//             int v = target[i] - 'a';
//             if (arr[u][v] == INT_MAX) {
//                 return -1;
//             }
//             ans += arr[u][v];
//         }
//         return ans;
//     }
// };