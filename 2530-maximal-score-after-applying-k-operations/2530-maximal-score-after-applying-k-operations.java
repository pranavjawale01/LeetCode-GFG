class Solution {
    public long maxKelements(int[] nums, int k) {
        long ans = 0;
        PriorityQueue<Long> pq = new PriorityQueue<>((a, b) -> Long.compare(b, a));
        for (int x : nums) {
            pq.add((long) x);
        }
        while (k-- > 0) {
            long top = pq.poll();
            ans += top;
            pq.add((long)Math.ceil((double)top / 3));
        }
        return ans;
    }
}