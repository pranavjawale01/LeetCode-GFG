class Solution {
    public int winningPlayerCount(int n, int[][] pick) {
        Map<Integer, Map<Integer, Integer>> mp = new HashMap<>();
        for (int[] x : pick) {
           mp.putIfAbsent(x[0], new HashMap<>());
           Map<Integer, Integer> hm = mp.get(x[0]);
           hm.put(x[1], hm.getOrDefault(x[1], 0) + 1);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int require = i + 1;
            boolean flag = false;
            if (mp.containsKey(i)) {
                for (int x : mp.get(i).values()) {
                    if (x >= require) {
                        flag = true;
                        break;
                    }
                }
            }
            if (flag) {
                ans++;
            }
        }
        return ans;
    }
}