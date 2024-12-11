class Solution {
    public int maximumBeauty(int[] nums, int k) {
        List<int[]> ranges = new ArrayList<>();
        for (int x : nums) {
            ranges.add(new int[]{x - k, x + k});
        }
        ranges.sort((a, b) -> Integer.compare(a[0], b[0]));

        int maxBeauty = 0;
        Deque<Integer> dq = new LinkedList<>();

        for (int[] range : ranges) {
            while (!dq.isEmpty() && dq.peekFirst() < range[0]) {
                dq.pollFirst();
            }
            dq.addLast(range[1]);
            maxBeauty = Math.max(maxBeauty, dq.size());
        }

        return maxBeauty;
    }
}