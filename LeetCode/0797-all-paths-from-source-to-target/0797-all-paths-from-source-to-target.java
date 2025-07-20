class Solution {
    public List<List<Integer>> ans;

    public void solve(Map<Integer, List<Integer>> mp, List<Integer> temp, int n, int source) {
        if (source == n - 1) {
            temp.add(source);
            ans.add(new ArrayList<>(temp));
            temp.remove(temp.size() - 1);
            return;
        }
        temp.add(source);
        for (int x : mp.get(source)) {
            solve(mp, temp, n, x);
        }
        temp.remove(temp.size() - 1);
    }

    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        int n = graph.length;
        ans = new ArrayList<>();
        Map<Integer, List<Integer>> mp = new HashMap<>();
        for (int i = 0; i < n; i++) {
            mp.put(i, new ArrayList<>());
            for (int x : graph[i]) {
                mp.get(i).add(x);
            }
        }
        List<Integer> temp = new ArrayList<>();
        solve(mp, temp, n, 0);
        return ans;
    }
}