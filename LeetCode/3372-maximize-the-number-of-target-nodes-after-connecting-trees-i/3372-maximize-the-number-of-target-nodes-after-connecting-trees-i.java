class Solution {
    public int bfs(Map<Integer, List<Integer>> mp, int start, int k, int size) {
        boolean[] vis = new boolean[size];
        Queue<Integer> q = new LinkedList<>();
        q.add(start);
        vis[start] = true;
        int cnt = 0, dist = 0;
        while (!q.isEmpty() && dist <= k) {
            int len = q.size();
            while (len-- > 0) {
                int node = q.poll();
                cnt++;
                for (int x : mp.get(node)) {
                    if (!vis[x]) {
                        vis[x] = true;
                        q.add(x);
                    }
                }
            }
            dist++;
        }
        return cnt;
    }

    public int[] maxTargetNodes(int[][] edges1, int[][] edges2, int k) {
        int n = edges1.length + 1, m = edges2.length + 1;
        Map<Integer, List<Integer>> mp1 = new HashMap<>();
        Map<Integer, List<Integer>> mp2 = new HashMap<>();
        for (int[] x : edges1) {
            mp1.putIfAbsent(x[0], new ArrayList<>());
            mp1.putIfAbsent(x[1], new ArrayList<>());
            mp1.get(x[0]).add(x[1]);
            mp1.get(x[1]).add(x[0]);
        }
        for (int[] x : edges2) {
            mp2.putIfAbsent(x[0], new ArrayList<>());
            mp2.putIfAbsent(x[1], new ArrayList<>());
            mp2.get(x[0]).add(x[1]);
            mp2.get(x[1]).add(x[0]);
        }
        int[] count = new int[n];
        for (int i = 0; i < n; i++) {
            count[i] = bfs(mp1, i, k, n);
        }
        int maxCountNode = 0;
        for (int i = 0; i < m; i++) {
            maxCountNode = Math.max(maxCountNode, bfs(mp2, i, k - 1, m));
        }
        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            ans[i] = count[i] + maxCountNode;
        }
        return ans;
    }
}