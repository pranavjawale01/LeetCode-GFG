class Solution {
    public void moveZeroes(int[] nums) {
        int i = 0;
        for (int j = 0; j < nums.length; j++) {
            if (nums[j] != 0) {
                int temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
                i++;
            }
        }
    }
}


// class Solution {
//     public void moveZeroes(int[] nums) {
//         int k = 0;
//         int count = 0;
//         int n = nums.length;
//         for (int i = 0; i < n; i++) {
//             if (nums[i] == 0) {
//                 count++;
//             } else {
//                 nums[k++] = nums[i];
//             }
//         }
//         for (int i = n - count; i < n; i++) {
//             nums[i] = 0;
//         }
//     }
// }