class Solution {
    public int minKBitFlips(int[] nums, int k) {
        int n = nums.length;
        int flips = 0;
        Deque<Integer> flipq = new LinkedList<>();
        int flipCountFromPastForCurri = 0;
        for (int i = 0; i < n; i++) {
            if (i >= k) {
                flipCountFromPastForCurri -= flipq.pollFirst();
            }
            if (flipCountFromPastForCurri % 2 == nums[i]) {
                if (i + k > n) {
                    return -1;
                }
                flipCountFromPastForCurri++;
                flipq.addLast(1);
                flips++;
            } else {
                flipq.addLast(0);
            }
        }
        return flips;
    }
}




// class Solution {
//     public int minKBitFlips(int[] nums, int k) {
//         int n = nums.length;
//         int flips = 0;
//         int flipCountFromtPastCurri = 0;
//         for (int i = 0; i < n; i++) {
//             if (i >= k && nums[i-k] == 2) {
//                 flipCountFromtPastCurri--;
//             }
//             if (flipCountFromtPastCurri % 2 == nums[i]) {
//                 if (i + k > n) {
//                     return -1;
//                 }
//                 flipCountFromtPastCurri++;
//                 nums[i] = 2;
//                 flips++;
//             }
//         }
//         return flips;
//     }
// }




// class Solution {
//     public int minKBitFlips(int[] nums, int k) {
//         int n = nums.length;
//         int flips = 0;
//         boolean[] isFlipped = new boolean[n];
//         int flipCountFromPastForCurri = 0;
//         for (int i = 0; i < n; i++) {
//             if (i >= k && isFlipped[i-k]) {
//                 flipCountFromPastForCurri--;
//             }
//             if (flipCountFromPastForCurri % 2 == nums[i]) {
//                 if (i + k > n) {
//                     return -1;
//                 }
//                 flipCountFromPastForCurri++;
//                 isFlipped[i] = true;
//                 flips++;
//             }
//         }
//         return flips;
//     }
// }