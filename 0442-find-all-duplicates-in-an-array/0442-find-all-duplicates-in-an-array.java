class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        int n = nums.length;
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int index = Math.abs(nums[i]) - 1;
            if (nums[index] < 0) {
                ans.add(Math.abs(nums[i]));
            } else {
                nums[index] *= (-1);
            }
        }
        return ans;
    }
}

// class Solution {
//     public List<Integer> findDuplicates(int[] nums) {
//         Arrays.sort(nums);
//         List<Integer> ans = new ArrayList<>();
//         for (int i = 1; i < nums.length; i++) {
//             if (nums[i] == nums[i-1]) {
//                 ans.add(nums[i-1]);
//             }
//         }
//         return ans;
//     }
// }

// // class Solution {
// //     public List<Integer> findDuplicates(int[] nums) {
// //         Map<Integer, Integer> mp = new HashMap<>();
// //         List<Integer> ans = new ArrayList<>();
// //         for (int num : nums) {
// //             mp.put(num, mp.getOrDefault(num, 0) + 1);
// //             if (mp.get(num) > 1) {
// //                 ans.add(num);
// //             }
// //         }
// //         return ans;
// //     }
// // }