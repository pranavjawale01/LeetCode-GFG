class Solution {
    public int[] sortedSquares(int[] nums) {
        int n = nums.length;
        int i = 0, j = n - 1, k = n - 1;
        int[] arr = new int[n];
        while (k >= 0) {
            int a = nums[i] * nums[i];
            int b = nums[j] * nums[j];
            if (a > b) {
                arr[k] = a;
                i++;
            } else {
                arr[k] = b;
                j--;
            }
            k--;
        }
        return arr;
    }
}

// class Solution {
//     public int[] sortedSquares(int[] nums) {
//         int n = nums.length;
//         for (int i = 0; i < n; i++) {
//             nums[i] = nums[i] * nums[i];
//         }
//         Arrays.sort(nums);
//         return nums;
//     }
// }