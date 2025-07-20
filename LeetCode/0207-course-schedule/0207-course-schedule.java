class Solution {
    private boolean isCyclic(Map<Integer, List<Integer>> mp, int v, boolean[] vis, boolean[] rec) {
        if (rec[v]) {
            return true;
        }
        if (vis[v]) {
            return false;
        }
        vis[v] = true;
        rec[v] = true;
        for (int x : mp.getOrDefault(v, new ArrayList<>())) {
            if (isCyclic(mp, x, vis, rec)) {
                return true;
            }
        }
        rec[v] = false;
        return false;
    }
    
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        Map<Integer, List<Integer>> mp = new HashMap<>();
        boolean[] vis = new boolean[numCourses];
        boolean[] rec = new boolean[numCourses];
        
        for (int[] x : prerequisites) {
            int u = x[1];
            int v = x[0];
            if (!mp.containsKey(u)) {
                mp.put(u, new ArrayList<>());
            }
            mp.get(u).add(v);
        }
        
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i] && isCyclic(mp, i, vis, rec)) {
                return false;
            }
        }
        
        return true;
    }
}




// class Solution {
//     public boolean canFinish(int numCourses, int[][] prerequisites) {
//         int[] indegree = new int[numCourses];
//         Map<Integer, List<Integer>> mp = new HashMap<>();
        
//         for (int[] x : prerequisites) {
//             if (!mp.containsKey(x[1])) {
//                 mp.put(x[1], new ArrayList<>());
//             }
//             mp.get(x[1]).add(x[0]);
//             indegree[x[0]]++;
//         }
        
//         Queue<Integer> q = new LinkedList<>();
//         int count = 0;
//         for (int i = 0; i < numCourses; i++) {
//             if (indegree[i] == 0) {
//                 q.add(i);
//                 count++;
//             }
//         }
        
//         while (!q.isEmpty()) {
//             int curr = q.poll();
//             if (mp.containsKey(curr)) {
//                 for (int x : mp.get(curr)) {
//                     indegree[x]--;
//                     if (indegree[x] == 0) {
//                         q.add(x);
//                         count++;
//                     }
//                 }
//             }
//         }
        
//         return count == numCourses;
//     }
// }