class Solution {
    public int maximumBeauty(int[] nums, int k) {
        Arrays.sort(nums);
        int maxBeauty = 0;
        for (int i = 0; i < nums.length; i++) {
            int upperBound = findUpperBound(nums, nums[i] + 2 * k);
            maxBeauty = Math.max(maxBeauty, upperBound - i);
        }
        return maxBeauty;
    }

    private int findUpperBound(int[] nums, int target) {
        int low = 0, high = nums.length;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
}








// class Solution {
//     public int maximumBeauty(int[] nums, int k) {
//         List<int[]> ranges = new ArrayList<>();
//         for (int x : nums) {
//             ranges.add(new int[]{x - k, x + k});
//         }
//         ranges.sort((a, b) -> Integer.compare(a[0], b[0]));

//         int maxBeauty = 0;
//         Deque<Integer> dq = new LinkedList<>();

//         for (int[] range : ranges) {
//             while (!dq.isEmpty() && dq.peekFirst() < range[0]) {
//                 dq.pollFirst();
//             }
//             dq.addLast(range[1]);
//             maxBeauty = Math.max(maxBeauty, dq.size());
//         }

//         return maxBeauty;
//     }
// }