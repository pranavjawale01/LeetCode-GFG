class Solution {
    private int solve(int[] nums, int k) {
        int count = 0, ans = 0, start = 0, end = 0;
        int n = nums.length;
        while (end < n) {
            if (nums[end] % 2 == 1) {
                count++;
            }
            while (count > k) {
                if (nums[start] % 2 == 1) {
                    count--;
                }
                start++;
            }
            ans += end - start + 1;
            end++;
        }
        return ans;
    }
    public int numberOfSubarrays(int[] nums, int k) {
        return solve(nums, k) - solve(nums, k-1);
    }
}



// class Solution {
//     public int numberOfSubarrays(int[] nums, int k) {
//         Map<Integer, Integer> mp = new HashMap<>();
//         int odd = 0;
//         int count = 0;
//         int n = nums.length;
//         for (int i = 0; i < n; i++) {
//             if (nums[i] % 2 == 1) {
//                 odd++;
//             }
//             if (odd == k) {
//                 count++;
//             }
//             if (mp.containsKey(odd - k)) {
//                 count += mp.get(odd - k);
//             }
//             if (mp.containsKey(odd)) {
//                 mp.put(odd, mp.getOrDefault(odd, 0) + 1);
//             } else {
//                 mp.put(odd, 1);
//             }
//         }
//         return count;
//     }
// }