class Solution {
    public long pickGifts(int[] gifts, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        long ans = 0;
        for (int x : gifts) {
            pq.offer(x);
            ans += x;
        }
        while (k-- > 0) {
            int maxEl = pq.poll();
            int sqrt = (int) Math.sqrt(maxEl);
            ans -= (maxEl - sqrt);
            pq.offer(sqrt);
        }
        return ans;
    }
}