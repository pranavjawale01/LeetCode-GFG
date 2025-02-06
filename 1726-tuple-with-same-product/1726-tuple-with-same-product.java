class Solution {
    public int tupleSameProduct(int[] nums) {
        int n = nums.length;
        Map<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                mp.put(nums[i] * nums[j], mp.getOrDefault(nums[i] * nums[j], 0) + 1);
            }
        }
        int ans = 0;
        for (int x : mp.values()) {
            ans += (x * (x - 1)) / 2;
        }
        return ans * 8;
    }
}




// class Solution {
//     public int tupleSameProduct(int[] nums) {
//         Arrays.sort(nums);
//         int n = nums.length, count = 0;

//         for (int i = 0; i < n; i++) {
//             for (int j = n - 1; j > i; j--) {
//                 int val = nums[i] * nums[j];
//                 Set<Integer> st = new HashSet<>();
//                 for (int k = i + 1; k < j; k++) {
//                     if (val % nums[k] == 0) {
//                         int data = val / nums[k];
//                         if (st.contains(data)) {
//                             count++;
//                         }
//                         st.add(nums[k]);
//                     }
//                 }
//             }
//         }
//         return count * 8;
//     }
// }