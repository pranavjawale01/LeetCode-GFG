class Solution {
    public int minOperations(int[] nums, int k) {
        PriorityQueue<Long> pq = new PriorityQueue<>();
        for (int x : nums) pq.offer((long)x);
        int count = 0;
        while (pq.size() >= 2 && pq.peek() < k) {
            long a = pq.poll();
            long b = pq.poll();
            pq.offer(Math.min(a, b) * 2 + Math.max(a, b));
            count++;
        }
        return count;
    }
}