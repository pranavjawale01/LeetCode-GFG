class Solution {
    public List<List<Integer>> getAncestors(int n, int[][] edges) {
        List<Integer>[] adj = new ArrayList[n];
        int[] indegree = new int[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }
        
        for (int[] edge : edges) {
            adj[edge[0]].add(edge[1]);
            indegree[edge[1]]++;
        }
        
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.add(i);
            }
        }
        
        Set<Integer>[] ancestors = new HashSet[n];
        for (int i = 0; i < n; i++) {
            ancestors[i] = new HashSet<>();
        }
        
        while (!q.isEmpty()) {
            int curr = q.poll();
            for (int neighbor : adj[curr]) {
                ancestors[neighbor].add(curr);
                ancestors[neighbor].addAll(ancestors[curr]);
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.add(neighbor);
                }
            }
        }
        
        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            List<Integer> list = new ArrayList<>(ancestors[i]);
            Collections.sort(list);
            ans.add(list);
        }
        
        return ans;
    }
}





// class Solution {
//     public void solve(Map<Integer, List<Integer>> mp, int node, List<Integer> temp, boolean[] vis) {
//         if (vis[node]) {
//             return;
//         }
//         vis[node] = true;
//         if (mp.containsKey(node)) {
//             for (int x : mp.get(node)) {
//                 if (!vis[x]) {
//                     temp.add(x);
//                     solve(mp, x, temp, vis);
//                 }
//             }
//         }
//     }

//     public List<List<Integer>> getAncestors(int n, int[][] edges) {
//         List<List<Integer>> ans = new ArrayList<>(n);
//         Map<Integer, List<Integer>> mp = new HashMap<>();

//         for (int i = 0; i < n; i++) {
//             ans.add(new ArrayList<>());
//         }

//         for (int[] edge : edges) {
//             mp.computeIfAbsent(edge[1], k -> new ArrayList<>()).add(edge[0]);
//         }

//         for (int i = 0; i < n; i++) {
//             List<Integer> temp = new ArrayList<>();
//             boolean[] vis = new boolean[n];
//             solve(mp, i, temp, vis);
//             Collections.sort(temp);
//             ans.set(i, temp);
//         }

//         return ans;
//     }
// }