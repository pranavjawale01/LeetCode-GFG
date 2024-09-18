class Solution {
    public int longestConsecutive(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }

        Set<Integer> set = new HashSet<>();

        for (int x : nums) set.add(x);

        int maxLen = 0;
        for (int num : set) {
            if (!set.contains(num - 1)) {
                int count = 1;
                while (set.contains(num + 1)) {
                    num++;
                    count++;
                }
                maxLen = Math.max(maxLen, count);
            }
        }

        return maxLen;
    }
}