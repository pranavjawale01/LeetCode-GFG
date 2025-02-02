class Solution {
    public boolean check(int[] nums) {
        int n = nums.length;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i+1) % n]) {
                count++;
            }
        }
        return count <= 1;
    }
}




// class Solution {
//     public boolean check(int[] nums) {
//         int n = nums.length;
//         int[] sorted = nums.clone();
//         Arrays.sort(sorted);

//         for (int r = 0; r < n; r++) {
//             boolean isSorted = true;
//             for (int i = 0; i < n; i++) {
//                 if (sorted[i] != nums[(i + r) % n]) {
//                     isSorted = false;
//                     break;
//                 }
//             }
//             if (isSorted) {
//                 return true;
//             }
//         }
//         return false;
//     }
// }









// // class Solution {
// //     public boolean check(int[] nums) {
// //         int n = nums.length;
// //         int[] sorted = new int[n];

// //         for (int r = 0; r < n; r++) {
// //             int idx = 0;
// //             for (int i = r; i < n; i++) {
// //                 sorted[idx++] = nums[i];
// //             }
// //             for (int i = 0; i < r; i++) {
// //                 sorted[idx++] = nums[i];
// //             }

// //             boolean isSorted = true;
// //             for (int i = 0; i < n - 1; i++) {
// //                 if (sorted[i] > sorted[i + 1]) {
// //                     isSorted = false;
// //                     break;
// //                 }
// //             }

// //             if (isSorted) {
// //                 return true;
// //             }
// //         }
// //         return false;
// //     }
// // }