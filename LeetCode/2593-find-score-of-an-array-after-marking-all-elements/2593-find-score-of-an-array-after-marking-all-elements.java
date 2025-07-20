class Solution {
    public long findScore(int[] nums) {
        long ans = 0;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
            if (a[0] != b[0]) return Integer.compare(a[0], b[0]);
            return Integer.compare(a[1], b[1]);
        });
        for (int i = 0; i < nums.length; i++) {
            pq.add(new int[]{nums[i], i});
        }
        int n = nums.length;
        boolean[] vis = new boolean[n];
        while (!pq.isEmpty()) {
            int[] top = pq.poll();
            int val = top[0];
            int idx = top[1];
            if (vis[idx]) continue;
            ans += val;
            vis[idx] = true;
            if (idx - 1 >= 0) vis[idx - 1] = true;
            if (idx + 1 < n) vis[idx + 1] = true;
        }
        return ans;
    }
}