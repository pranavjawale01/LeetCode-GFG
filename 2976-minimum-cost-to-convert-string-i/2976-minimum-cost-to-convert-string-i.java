class Solution {
    private void bellmanFord(long[][] arr, int s) {
        int V = arr.length;
        long[] dist = new long[V];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[s] = 0;
        for (int i = 0; i < V - 1; i++) {
            for (int u = 0; u < V; u++) {
                for (int v = 0; v < V; v++) {
                    if (dist[u] != Integer.MAX_VALUE && dist[u] + arr[u][v] < dist[v]) {
                        dist[v] = dist[u] + arr[u][v];
                    }
                }
            }
        }
        for (int i = 0; i < V; i++) {
            arr[s][i] = dist[i];
        }
    }
    public long minimumCost(String source, String target, char[] original, char[] changed, int[] cost) {
        long[][] arr = new long[26][26];
        for (int i = 0; i < 26; i++) {
            Arrays.fill(arr[i], Integer.MAX_VALUE);
        }
        int n = original.length;
        for (int i = 0; i < n; i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            arr[u][v] = Math.min((long)(cost[i]), arr[u][v]);
        }
        for (int i = 0; i < 26; i++) {
            arr[i][i] = 0;
        }
        for (int i = 0; i < 26; i++) {
            bellmanFord(arr, i);
        }
        n = target.length();
        long ans = 0;
        for (int i = 0; i < n; i++) {
            int u = source.charAt(i) - 'a';
            int v = target.charAt(i) - 'a';
            if (arr[u][v] == Integer.MAX_VALUE) {
                return -1;
            }
            ans += arr[u][v];
        }
        return ans;
    }
}










// class Solution {
//     private void floydWarshall(long[][] arr) {
//         long val = Integer.MAX_VALUE;
//         for (int via = 0; via < 26; via++) {
//             for (int i = 0; i < 26; i++) {
//                 for (int j = 0; j < 26; j++) {
//                     if (arr[i][via] < val && arr[via][j] < val) {
//                         arr[i][j] = Math.min(arr[i][j], arr[i][via] + arr[via][j]);
//                     }
//                 }
//             }
//         }
//     }
//     public long minimumCost(String source, String target, char[] original, char[] changed, int[] cost) {
//         long[][] arr = new long[26][26];
//         for (int i = 0; i < 26; i++) {
//             Arrays.fill(arr[i], Integer.MAX_VALUE);
//         }
//         int n = original.length;
//         for (int i = 0; i < n; i++) {
//             int u = original[i] - 'a';
//             int v = changed[i] - 'a';
//             arr[u][v] = Math.min((long)(cost[i]), arr[u][v]);
//         }
//         for (int i = 0; i < 26; i++) {
//             arr[i][i] = 0;
//         }
//         floydWarshall(arr);
//         n = target.length();
//         long ans = 0;
//         for (int i = 0; i < n; i++) {
//             int u = source.charAt(i) - 'a';
//             int v = target.charAt(i) - 'a';
//             if (arr[u][v] == Integer.MAX_VALUE) {
//                 return -1;
//             }
//             ans += arr[u][v];
//         }
//         return ans;
//     }
// }