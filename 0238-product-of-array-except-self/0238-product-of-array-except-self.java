class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] left = new int[n];
        Arrays.fill(left, 1);
        for (int i = 1; i < n; i++) {
            left[i] = left[i - 1] * nums[i - 1];
        }
        int right = 1;
        for (int i = n - 1; i >= 0; i--) {
            left[i] *= right;
            right *= nums[i];
        }
        return left;
    }
}

// class Solution {
//     public int[] productExceptSelf(int[] nums) {
//         int n = nums.length;
//         int[] left = new int[n];
//         int[] right = new int[n];
//         Arrays.fill(left, 1);
//         Arrays.fill(right, 1);
//         for (int i = 1; i < n; i++) {
//             left[i] = left[i-1]*nums[i-1];
//             right[n-i-1] = right[n-i]*nums[n-i];
//         }
//         for (int i = 0; i < n; i++) {
//             nums[i] = left[i] * right[i];
//         }
//         return nums;
//     }
// }

// class Solution {
//     public int[] productExceptSelf(int[] nums) {
//         int n = nums.length;
//         int zeroCount = 0, productWithoutZero = 1;
//         for (int num : nums) {
//             if (num == 0) {
//                 zeroCount++;
//             } else {
//                 productWithoutZero *= num;
//             }
//         }
//         for (int i = 0; i < n; i++) {
//             int num = nums[i];
//             if (num != 0) {
//                 if (zeroCount > 0) {
//                     nums[i] = 0;
//                 } else {
//                     nums[i] = productWithoutZero / num;
//                 }
//             } else {
//                 if (zeroCount > 1) {
//                     nums[i] = 0;
//                 } else {
//                     nums[i] = productWithoutZero;
//                 }
//             }
//         }
//         return nums;
//     }
// }

// Brute Force
// class Solution {
//     public int[] productExceptSelf(int[] nums) {
//         int n = nums.length;
//         int[] temp = new int[n];
//         for (int i = 0; i < n; i++) {
//             int tem = 1;
//             for (int j = 0; j < n; j++) {
//                 if (i == j) {
//                     continue;
//                 }
//                 tem *= nums[j];
//             }
//             temp[i] = tem;
//         }
//         return temp;
//     }
// }