class Solution {
    public boolean canSortArray(int[] nums) {
        int numOfSetBits = Integer.bitCount(nums[0]);
        int maxOfSegment = nums[0];
        int minOfSegment = nums[0];
        int maxOfPrevSegment = Integer.MIN_VALUE;

        for (int i = 1; i < nums.length; i++) {
            if (Integer.bitCount(nums[i]) == numOfSetBits) {
                maxOfSegment = Math.max(maxOfSegment, nums[i]);
                minOfSegment = Math.min(minOfSegment, nums[i]);
            } else {
                if (minOfSegment < maxOfPrevSegment) {
                    return false;
                }
                maxOfPrevSegment = maxOfSegment;
                maxOfSegment = nums[i];
                minOfSegment = nums[i];
                numOfSetBits = Integer.bitCount(nums[i]);
            }
        }
        
        return minOfSegment >= maxOfPrevSegment;
    }
}





// class Solution {
//     public boolean canSortArray(int[] nums) {
//         int n = nums.length;
//         boolean swapped = true;
//         for (int i = 0; i < n; i++) {
//             swapped = false;
//             for (int j = 0; j < n - i - 1; j++) {
//                 if (nums[j] <= nums[j + 1]) {
//                     continue;
//                 } else {
//                     if (Integer.bitCount(nums[j]) == Integer.bitCount(nums[j + 1])) {
//                         int temp = nums[j];
//                         nums[j] = nums[j + 1];
//                         nums[j + 1] = temp;
//                         swapped = true;
//                     } else {
//                         return false;
//                     }
//                 }
//             }
//             if (!swapped) {
//                 break;
//             }
//         }
//         return true;
//     }
// }