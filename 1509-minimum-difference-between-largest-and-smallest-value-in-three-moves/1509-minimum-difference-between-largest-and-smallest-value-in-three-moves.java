class Solution {
    public int minDifference(int[] nums) {
        int n = nums.length;
        if (n <= 4) {
            return 0;
        }
        
        PriorityQueue<Integer> pqMax = new PriorityQueue<>(Collections.reverseOrder());
        PriorityQueue<Integer> pqMin = new PriorityQueue<>();
        
        for (int num : nums) {
            pqMin.add(num);
            pqMax.add(num);
            if (pqMax.size() > 4) {
                pqMax.poll();
            }
            if (pqMin.size() > 4) {
                pqMin.poll();
            }
        }
        
        int l = 3, r = n - 4;
        
        while (!pqMax.isEmpty()) {
            nums[l--] = pqMax.poll();
            nums[r++] = pqMin.poll();
        }
        
        return Math.min(Math.min(nums[n-1] - nums[3], nums[n-2] - nums[2]), Math.min(nums[n-3] - nums[1], nums[n-4] - nums[0]));
    }
}






// class Solution {
//     public int minDifference(int[] nums) {
//         int n = nums.length;
//         if (n <= 4) {
//             return 0;
//         }
//         Arrays.sort(nums);
//         int minDiff = Integer.MAX_VALUE;
//         minDiff = Math.min(minDiff, nums[n-1] - nums[3]);
//         minDiff = Math.min(minDiff, nums[n-2] - nums[2]);
//         minDiff = Math.min(minDiff, nums[n-3] - nums[1]);
//         minDiff = Math.min(minDiff, nums[n-4] - nums[0]);
//         return minDiff;
//     }
// }