class Solution {
    private boolean cycleDetected = false;

    private void dfs(Map<Integer, List<Integer>> mp, int u, boolean[] vis, boolean[] rec, Stack<Integer> st) {
        vis[u] = true;
        rec[u] = true;
        for (int v : mp.getOrDefault(u, new ArrayList<>())) {
            if (rec[v]) {
                cycleDetected = true;
                return;
            }
            if (!vis[v]) {
                dfs(mp, v, vis, rec, st);
                if (cycleDetected) return;
            }
        }
        st.push(u);
        rec[u] = false;
    }

    public int[] findOrder(int numCourses, int[][] prerequisites) {
        Map<Integer, List<Integer>> mp = new HashMap<>();
        for (int[] x : prerequisites) {
            mp.computeIfAbsent(x[1], k -> new ArrayList<>()).add(x[0]);
        }
        
        boolean[] rec = new boolean[numCourses];
        boolean[] vis = new boolean[numCourses];
        Stack<Integer> st = new Stack<>();

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                dfs(mp, i, vis, rec, st);
                if (cycleDetected) return new int[0];
            }
        }

        int[] result = new int[st.size()];
        for (int i = 0; i < result.length; i++) {
            result[i] = st.pop();
        }

        return result;
    }
}






// class Solution {
//     public int[] findOrder(int numCourses, int[][] prerequisites) {
//         Map<Integer, List<Integer>> mp = new HashMap<>();
//         int[] indegree = new int[numCourses];
        
//         for (int i = 0; i < numCourses; i++) {
//             mp.put(i, new ArrayList<>());
//         }
        
//         for (int[] x : prerequisites) {
//             mp.get(x[1]).add(x[0]);
//             indegree[x[0]]++;
//         }
        
//         Queue<Integer> q = new LinkedList<>();
//         int count = 0;
//         int[] ans = new int[numCourses];
        
//         for (int i = 0; i < numCourses; i++) {
//             if (indegree[i] == 0) {
//                 q.offer(i);
//                 ans[count] = i;
//                 count++;
//             }
//         }
        
//         while (!q.isEmpty()) {
//             int x = q.poll();
//             for (int v : mp.get(x)) {
//                 indegree[v]--;
//                 if (indegree[v] == 0) {
//                     q.offer(v);
//                     ans[count] = v;
//                     count++;
//                 }
//             }
//         }
        
//         if (count == numCourses) {
//             return ans;
//         }
        
//         return new int[0];
//     }
// }