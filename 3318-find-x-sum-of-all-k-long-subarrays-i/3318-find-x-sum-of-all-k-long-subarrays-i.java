class Solution {
    public int[] findXSum(int[] nums, int k, int x) {
        int[] result = new int[nums.length - k + 1];
        for (int i = 0; i <= nums.length - k; i++) {
            result[i] = getSum(nums, i, i + k - 1, x);
        }
        return result;
    }

    public int getSum(int[] nums, int start, int end, int x) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = start; i <= end; i++) {
            map.put(nums[i], map.getOrDefault(nums[i], 0) + 1);
        }
        PriorityQueue<Map.Entry<Integer, Integer>> priorityQueue = new PriorityQueue<>(
            (a, b) -> a.getValue() == b.getValue() ? -Integer.compare(a.getKey(), b.getKey()) : -Integer.compare(a.getValue(), b.getValue())
        );
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            priorityQueue.offer(entry);
        }
        int sum = 0;
        while (x > 0 && !priorityQueue.isEmpty()) {
            Map.Entry<Integer, Integer> pair = priorityQueue.poll();
            sum += pair.getKey() * pair.getValue();
            x--;
        }
        return sum;
    }
}