class Solution {
    public int findMaxK(int[] nums) {
        int[] arr = new int[2001];
        Arrays.fill(arr, 0);
        int result = -1;
        for (int num : nums) {
            if (arr[-num + 1000] == 1) {
                result = Math.max(result, Math.abs(num));
            } 
            arr[num + 1000] = 1;
        }
        return result;
    }
}


// class Solution {
//     public int findMaxK(int[] nums) {
//         Set<Integer> st = new HashSet<>();
//         int ans = -1;
//         for (int num : nums) {
//             if (st.contains(-num)) {
//                 ans = Math.max(ans, Math.abs(num));
//             } else {
//                 st.add(num);
//             }
//         }
//         return ans;
//     }
// }


// class Solution {
//     public int findMaxK(int[] nums) {
//         Arrays.sort(nums);
//         int low = 0, high = nums.length - 1;
//         while (low <= high) {
//             if ((nums[low]*(-1)) == nums[high]) {
//                 return nums[high];
//             } else if ((nums[low]*(-1)) < nums[high]) {
//                 high--;
//             } else {
//                 low++;
//             }
//         }
//         return -1;
//     }
// }