class Solution {
    public int minSwaps(int[] nums) {
        int n = nums.length;
        int totalOnes = Arrays.stream(nums).sum();
        int i = 0, j = 0;
        int currOnes = 0, maxCount = 0;
        while (j < 2 * n) {
            if (nums[j%n] == 1) {
                currOnes++;
            }
            if (j - i + 1 > totalOnes) {
                currOnes -= nums[i%n];
                i++;
            }
            maxCount = Math.max(maxCount, currOnes);
            j++;
        }
        return totalOnes - maxCount;
    }
}




// class Solution {
//     public int minSwaps(int[] nums) {
//         int n = nums.length;
//         int[] temp = new int[2 * n];
//         for (int i = 0; i < 2 * n; i++) {
//             temp[i] = nums[i % n];
//         }
//         int totalOnes = Arrays.stream(nums).sum();
//         int i = 0, j = 0;
//         int currOnes = 0, maxCount = 0;
//         while (j < 2 * n) {
//             if (temp[j] == 1) {
//                 currOnes++;
//             }
//             if (j - i + 1 > totalOnes) {
//                 currOnes -= temp[i];
//                 i++;
//             }
//             maxCount = Math.max(maxCount, currOnes);
//             j++;
//         }
//         return totalOnes - maxCount;
//     }
// }