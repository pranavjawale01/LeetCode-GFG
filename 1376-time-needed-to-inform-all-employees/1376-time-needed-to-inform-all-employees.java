class Solution {
    public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
        Map<Integer, ArrayList<Integer>> adj = new HashMap<>();
        for (int i = 0; i < n; i++) {
            if (manager[i] == -1) {
                continue;
            }
            adj.putIfAbsent(manager[i], new ArrayList<>());
            adj.get(manager[i]).add(i);
        }
        return bfs(headID, adj, informTime);
    }

    public int bfs(int headId, Map<Integer, ArrayList<Integer>> adj, int[] informTime) {
        if (!adj.containsKey(headId) || adj.get(headId).isEmpty()) {
            return 0;
        }
        int maxTime = 0;
        Queue<Pair<Integer, Integer>> q = new LinkedList<>();
        q.offer(new Pair<>(headId, 0));
        while (!q.isEmpty()) {
            Pair<Integer, Integer> curr = q.poll();
            maxTime = Math.max(maxTime, curr.getValue());
            if (adj.containsKey(curr.getKey())) {
                for (int sub : adj.get(curr.getKey())) {
                    q.offer(new Pair<>(sub, curr.getValue() + informTime[curr.getKey()]));
                }
            }
        }
        return maxTime;
    }
}




// class Solution {
//     public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
//         Map<Integer, ArrayList<Integer>> adj = new HashMap<>();
//         for (int i = 0; i < n; i++) {
//             if (manager[i] == -1) {
//                 continue;
//             }
//             adj.putIfAbsent(manager[i], new ArrayList<>());
//             adj.get(manager[i]).add(i);
//         }
//         return dfs(headID, adj, informTime);
//     }

//     public int dfs(int headId, Map<Integer, ArrayList<Integer>> adj, int[] informTime) {
//         if (!adj.containsKey(headId) || adj.get(headId).isEmpty()) {
//             return 0;
//         }
//         int maxTime = 0;
//         for (int sub : adj.get(headId)) {
//             maxTime = Math.max(maxTime, dfs(sub, adj, informTime));
//         }
//         return maxTime + informTime[headId];
//     }
// }