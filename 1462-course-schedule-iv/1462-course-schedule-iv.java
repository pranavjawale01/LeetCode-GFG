class Solution {
    Map<Integer, List<Integer>> mp = new HashMap<>();

    public boolean solve(int s, int e, boolean[] vis) {
        vis[s] = true;
        if (s == e) return true;
        boolean reachable = false;
        for (int x : mp.getOrDefault(s, new ArrayList<>())) {
            if (!vis[x]) {
                reachable |= solve(x, e, vis);
            }
        }
        return reachable;
    }

    public void help(int numCourses, boolean[][] check) {
        for (int i = 0; i < numCourses; i++) {
            for (int j = 0; j < numCourses; j++) {
                if (i != j) {
                    boolean[] vis = new boolean[numCourses];
                    if (solve(i, j, vis)) {
                        check[i][j] = true;
                    }
                }
            }
        }
    }

    public List<Boolean> checkIfPrerequisite(int numCourses, int[][] prerequisites, int[][] queries) {
        for (int[] pair : prerequisites) {
            mp.computeIfAbsent(pair[0], k -> new ArrayList<>()).add(pair[1]);
        }
        boolean[][] check = new boolean[numCourses][numCourses];
        help(numCourses, check);

        List<Boolean> ans = new ArrayList<>();
        for (int[] query : queries) {
            ans.add(check[query[0]][query[1]]);
        }
        return ans;
    }
}








// class Solution {
//     public boolean solve(Map<Integer, List<Integer>> mp, int s, int e, boolean[] vis) {
//         vis[s] = true;
//         if (s == e) return true;
//         boolean reachable = false;
//         for (int x : mp.getOrDefault(s, new ArrayList<>())) {
//             if (!vis[x]) {
//                 reachable |= solve(mp, x, e, vis);
//             }
//         }
//         return reachable;
//     }

//     public List<Boolean> checkIfPrerequisite(int numCourses, int[][] prerequisites, int[][] queries) {
//         Map<Integer, List<Integer>> mp = new HashMap<>();
//         for (int[] pair : prerequisites) {
//             mp.computeIfAbsent(pair[0], k -> new ArrayList<>()).add(pair[1]);
//         }
//         List<Boolean> ans = new ArrayList<>();
//         for (int[] query : queries) {
//             int u = query[0];
//             int v = query[1];
//             boolean[] vis = new boolean[numCourses];
//             ans.add(solve(mp, u, v, vis));
//         }
//         return ans;
//     }
// }