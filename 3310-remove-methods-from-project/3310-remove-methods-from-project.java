class Solution {
    public void dfs(int node, List<Integer>[] adj, boolean[] vis) {
        vis[node] = true;
        for (int x : adj[node]) {
            if (!vis[x]) {
                dfs(x, adj, vis);
            }
        }
    }
    
    public List<Integer> remainingMethods(int n, int k, int[][] invocations) {
        List<Integer>[] adj = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }
        
        for (int[] x : invocations) {
            int u = x[0];
            int v = x[1];
            adj[u].add(v);
        }

        boolean[] vis = new boolean[n];
        dfs(k, adj, vis);

        boolean suspicious = true;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                for (int x : adj[i]) {
                    if (vis[x]) {
                        suspicious = false;
                    }
                }
            }
        }

        // Prepare result
        List<Integer> ans = new ArrayList<>();
        if (suspicious) {
            for (int i = 0; i < n; i++) {
                if (!vis[i]) {
                    ans.add(i);
                }
            }
        } else {
            for (int i = 0; i < n; i++) {
                ans.add(i);
            }
        }

        return ans;
    }
}












// TLE
// class Solution {
//     public List<Integer> remainingMethods(int n, int k, int[][] invocations) {
//         Set<Integer> bug = new HashSet<>();
//         bug.add(k);
//         boolean flag;

//         do {
//             flag = false;
//             for (int[] x : invocations) {
//                 int a = x[0], b = x[1];
//                 if (bug.contains(a) && !bug.contains(b)) {
//                     bug.add(b);
//                     flag = true;
//                 }
//             }
//         } while (flag);

//         for (int[] x : invocations) {
//             int a = x[0], b = x[1];
//             if (!bug.contains(a) && bug.contains(b)) {
//                 List<Integer> ans = new ArrayList<>();
//                 for (int i = 0; i < n; i++) ans.add(i);
//                 return ans;
//             }
//         }

//         List<Integer> ans = new ArrayList<>();
//         for (int i = 0; i < n; i++) {
//             if (!bug.contains(i)) ans.add(i);
//         }
//         return ans;
//     }
// }