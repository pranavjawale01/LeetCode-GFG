class Solution {
    public int longestSubarray(int[] nums, int limit) {
        int n = nums.length;
        TreeMap<Integer, Integer> mp = new TreeMap<>();
        int i = 0, j = 0, maxlen = 0;
        while (j < n) {
            mp.put(nums[j], mp.getOrDefault(nums[j], 0) + 1);
            while (mp.lastKey() - mp.firstKey() > limit) {
                mp.put(nums[i], mp.get(nums[i]) - 1);
                if (mp.get(nums[i]) == 0) {
                    mp.remove(nums[i]);
                }
                i++;
            }
            maxlen = Math.max(maxlen, j - i + 1);
            j++;
        }
        return maxlen;
    }
}




// class Solution {
//     public int longestSubarray(int[] nums, int limit) {
//         int n = nums.length;
//         PriorityQueue<int[]> mpq = new PriorityQueue<>((a, b) -> b[0] - a[0]);
//         PriorityQueue<int[]> lpq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
//         int i = 0, j = 0;
//         int maxlen = 0;
//         while (j < n) {
//             mpq.offer(new int[]{nums[j], j});
//             lpq.offer(new int[]{nums[j], j});
//             while (mpq.peek()[0] - lpq.peek()[0] > limit) {
//                 i = Math.min(mpq.peek()[1], lpq.peek()[1]) + 1;
//                 while (mpq.peek()[1] < i) {
//                     mpq.poll();
//                 }
//                 while (lpq.peek()[1] < i) {
//                     lpq.poll();
//                 }
//             }
//             maxlen = Math.max(maxlen, j - i + 1);
//             j++;
//         }
//         return maxlen;
//     }
// }