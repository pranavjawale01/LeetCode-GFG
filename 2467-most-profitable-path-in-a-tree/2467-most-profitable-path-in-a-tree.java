class Solution {
    Map<Integer, List<Integer>> adj = new HashMap<>();
    Map<Integer, Integer> bobMap = new HashMap<>();
    int aliceIncome;

    private boolean DFSBob(int curr, int t, boolean[] visited) {
        visited[curr] = true;
        bobMap.put(curr, t);

        if (curr == 0) {
            return true;
        }

        for (int neighbor : adj.getOrDefault(curr, new ArrayList<>())) {
            if (!visited[neighbor]) {
                if (DFSBob(neighbor, t + 1, visited)) {
                    return true;
                }
            }
        }

        bobMap.remove(curr);
        return false;
    }

    public int mostProfitablePath(int[][] edges, int bob, int[] amount) {
        int n = amount.length;
        aliceIncome = Integer.MIN_VALUE;

        for (int[] edge : edges) {
            adj.computeIfAbsent(edge[0], k -> new ArrayList<>()).add(edge[1]);
            adj.computeIfAbsent(edge[1], k -> new ArrayList<>()).add(edge[0]);
        }

        boolean[] visited = new boolean[n];
        DFSBob(bob, 0, visited);

        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{0, 0, 0});
        Arrays.fill(visited, false);

        while (!queue.isEmpty()) {
            int[] currNode = queue.poll();
            int curr = currNode[0], t = currNode[1], income = currNode[2];

            if (!bobMap.containsKey(curr) || bobMap.get(curr) > t) {
                income += amount[curr];
            } else if (bobMap.get(curr) == t) {
                income += amount[curr] / 2;
            }

            if (adj.getOrDefault(curr, new ArrayList<>()).size() == 1 && curr != 0) {
                aliceIncome = Math.max(aliceIncome, income);
            }

            for (int neighbor : adj.getOrDefault(curr, new ArrayList<>())) {
                if (!visited[neighbor]) {
                    queue.offer(new int[]{neighbor, t + 1, income});
                }
            }

            visited[curr] = true;
        }

        return aliceIncome;
    }
}