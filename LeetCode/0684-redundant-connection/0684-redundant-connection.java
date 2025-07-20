class DSU {
    int[] parent, rank;

    DSU(int n) {
        parent = new int[n + 1];
        rank = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void union(int x, int y) {
        int xpar = find(x), ypar = find(y);
        if (xpar == ypar) return;
        if (rank[xpar] > rank[ypar]) {
            parent[ypar] = xpar;
        } else if (rank[ypar] > rank[xpar]) {
            parent[xpar] = ypar;
        } else {
            parent[ypar] = xpar;
            rank[xpar]++;
        }
    }
}

class Solution {
    public int[] findRedundantConnection(int[][] edges) {
        int n = edges.length;
        DSU dsu = new DSU(n);
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1];
            if (dsu.find(u) == dsu.find(v)) return edge;
            dsu.union(u, v);
        }
        return new int[0];
    }
}






// class Solution {
//     public boolean bfs(Map<Integer, List<Integer>> mp, int u, int v, boolean[] vis) {
//         Queue<Integer> q = new LinkedList<>();
//         q.offer(u);
//         while (!q.isEmpty()) {
//             int curr = q.poll();
//             vis[curr] = true;
//             if (curr == v) return true;
//             for (int x : mp.get(curr)) {
//                 if (vis[x] == false) {
//                     q.offer(x);
//                 }
//             }
//         }
//         return false;
//     }

//     public int[] findRedundantConnection(int[][] edges) {
//         int n = edges.length;
//         Map<Integer, List<Integer>> mp = new HashMap<>();
//         for (int[] edge : edges) {
//             int u = edge[0], v = edge[1];
//             boolean[] vis = new boolean[n + 1];
//             if (mp.containsKey(u) && mp.containsKey(v) && bfs(mp, u, v, vis)) {
//                 return edge;
//             }
//             mp.putIfAbsent(u, new ArrayList<>());
//             mp.putIfAbsent(v, new ArrayList<>());
//             mp.get(u).add(v);
//             mp.get(v).add(u);
//         }
//         return new int[0];
//     }
// }




// // class Solution {
// //     public boolean dfs(Map<Integer, List<Integer>> mp, int u, int v, boolean[] vis) {
// //         vis[u] = true;
// //         if (u == v) return true;
// //         for (int x : mp.get(u)) {
// //             if (vis[x]) continue;
// //             if (dfs(mp, x, v, vis)) return true;
// //         }
// //         return false;
// //     }

// //     public int[] findRedundantConnection(int[][] edges) {
// //         int n = edges.length;
// //         Map<Integer, List<Integer>> mp = new HashMap<>();
// //         for (int[] edge : edges) {
// //             int u = edge[0], v = edge[1];
// //             boolean[] vis = new boolean[n + 1];
// //             if (mp.containsKey(u) && mp.containsKey(v) && dfs(mp, u, v, vis)) {
// //                 return edge;
// //             }
// //             mp.putIfAbsent(u, new ArrayList<>());
// //             mp.putIfAbsent(v, new ArrayList<>());
// //             mp.get(u).add(v);
// //             mp.get(v).add(u);
// //         }
// //         return new int[0];
// //     }
// // }