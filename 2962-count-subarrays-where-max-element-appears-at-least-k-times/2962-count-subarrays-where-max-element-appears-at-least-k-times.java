class Solution {
    public long countSubarrays(int[] nums, int k) {
        int maxE = Arrays.stream(nums).max().getAsInt();
        int n = nums.length;
        long result = 0;
        ArrayList<Integer> id = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == maxE) {
                id.add(i);
            }
            int size = id.size();
            if (size >= k) {
                int last_i = id.get(size - k);
                result += last_i + 1;
            }
        }
        return result;
    }
}

// class Solution {
//     public long countSubarrays(int[] nums, int k) {
//         int maxE = Arrays.stream(nums).max().getAsInt();
//         int i = 0, j = 0, n = nums.length, countMax = 0;
//         long result = 0;
//         while (j < n) {
//             if (nums[j] == maxE) {
//                 countMax++;
//             }
//             while (countMax >= k) {
//                 result += n - j;
//                 if (nums[i] == maxE) {
//                     countMax--;
//                 }
//                 i++;
//             }
//             j++;
//         }
//         return result;
//     }
// }