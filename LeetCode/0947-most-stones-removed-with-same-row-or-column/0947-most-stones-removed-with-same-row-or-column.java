class Solution {
    public int[] parent;
    public int[] rank;
    public int n;

    private int find(int i) {
        if (i != parent[i]) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }

    private void union(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);
        if (root_u != root_v) {
            if (rank[root_u] > rank[root_v]) {
                parent[root_v] = root_u;
            } else if (rank[root_u] < rank[root_v]) {
                parent[root_u] = root_v;
            } else {
                parent[root_v] = root_u;
                rank[root_v]++;
            }
        }
    }

    public int removeStones(int[][] stones) {
        n = stones.length;
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = i;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    union(i, j);
                }
            }
        }
        int group = 0;
        for (int i = 0; i < n; i++) {
            if (i == parent[i]) {
                group++;
            }
        }
        return n - group;
    }
}






// class Solution {
//     public int n;
//     public void dfs(int[][] stones, int idx, boolean[] vis) {
//         vis[idx] = true;
//         for (int i = 0; i < n; i++) {
//             if (!vis[i] && ((stones[i][0] == stones[idx][0]) || stones[i][1] == stones[idx][1])) {
//                 dfs(stones, i, vis);
//             }
//         }
//     }
//     public int removeStones(int[][] stones) {
//         n = stones.length;
//         boolean[] vis = new boolean[n];
//         int count = 0;
//         for (int i = 0; i < n; i++) {
//             if (vis[i]) {
//                 continue;
//             }
//             dfs(stones, i, vis);
//             count++;
//         }
//         return n - count;
//     }
// }