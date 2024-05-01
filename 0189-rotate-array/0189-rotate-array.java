class Solution {
    public void rotate(int[] nums, int k) {
        k = k % nums.length;
        
        reverse(nums, 0, nums.length - k);
        reverse(nums, nums.length - k, nums.length);
        reverse(nums, 0, nums.length);
    }
    
    private void reverse(int[] nums, int start, int end) {
        while (start < end) {
            int temp = nums[start];
            nums[start] = nums[end - 1];
            nums[end - 1] = temp;
            start++;
            end--;
        }
    }
}



// class Solution {
//     public void rotate(int[] nums, int k) {
//         int n = nums.length;
//         k = k % n;

//         List<Integer> temp = new ArrayList<>();
//         for (int i = n - k; i < n; i++) {
//             temp.add(nums[i]);
//         }

//         for (int i = n - 1; i >= k; i--) {
//             nums[i] = nums[i - k];
//         }

//         for (int i = 0; i < k; i++) {
//             nums[i] = temp.get(i);
//         }
//     }
// }