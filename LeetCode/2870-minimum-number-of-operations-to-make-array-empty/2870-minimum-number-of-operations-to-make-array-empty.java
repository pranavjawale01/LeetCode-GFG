class Solution {
    public int minOperations(int[] nums) {
        Map<Integer, Integer> count = new HashMap<Integer, Integer>();
        for (int num: nums) {
            count.put(num, count.getOrDefault(num, 0) + 1);
        }
        int total = 0;
        for (int c : count.values()) {
            if (c == 1) {
                return -1;
            }
            total += Math.ceil((double) c / 3);
        }
        return total;
    }
}