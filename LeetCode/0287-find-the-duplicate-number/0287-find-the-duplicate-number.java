class Solution {
    public int findDuplicate(int[] nums) {
        int slow = nums[0];
        int fast = nums[0];
        slow = nums[slow];
        fast = nums[nums[fast]];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
}

// class Solution {
//     public int findDuplicate(int[] nums) {
//         int n = nums.length;
//         for (int i = 0; i < n; i++) {
//             int index = Math.abs(nums[i]) - 1;
//             if (nums[index] < 0) {
//                 return Math.abs(nums[i]);
//             }
//             nums[index] = nums[index] * (-1); 
//         }
//         return -1;
//     }
// }

// // class Solution {
// //     public int findDuplicate(int[] nums) {
// //         Map<Integer, Integer> mp = new HashMap<>();
// //         for (int num : nums) {
// //             mp.put(num, mp.getOrDefault(num, 0) + 1);
// //             if (mp.get(num) > 1) {
// //                 return num;
// //             }
// //         }
// //         return -1;
// //     }
// // }