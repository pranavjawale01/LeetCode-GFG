class Solution {
    public long continuousSubarrays(int[] nums) {
        int n = nums.length;
        PriorityQueue<int[]> minpq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        PriorityQueue<int[]> maxpq = new PriorityQueue<>((a, b) -> b[0] - a[0]);
        int i = 0, j = 0;
        long count = 0;
        while (j < n) {
            minpq.offer(new int[]{nums[j], j});
            maxpq.offer(new int[]{nums[j], j});
            while (Math.abs(maxpq.peek()[0] - minpq.peek()[0]) > 2) {
                i++;
                while (!maxpq.isEmpty() && maxpq.peek()[1] < i) {
                    maxpq.poll();
                }
                while (!minpq.isEmpty() && minpq.peek()[1] < i) {
                    minpq.poll();
                }
            }
            count += j - i + 1;
            j++;
        }
        return count;
    }
}












// class Solution {
//     public long continuousSubarrays(int[] nums) {
//         int n = nums.length;
//         TreeMap<Integer, Integer> map = new TreeMap<>();
//         int i = 0, j = 0;
//         long count = 0;
//         while (j < n) {
//             map.put(nums[j], map.getOrDefault(nums[j], 0) + 1);
//             while (map.lastKey() - map.firstKey() > 2) {
//                 map.put(nums[i], map.get(nums[i]) - 1);
//                 if (map.get(nums[i]) == 0) {
//                     map.remove(nums[i]);
//                 }
//                 i++;
//             }
//             count += j - i + 1;
//             j++;
//         }
//         return count;
//     }
// }