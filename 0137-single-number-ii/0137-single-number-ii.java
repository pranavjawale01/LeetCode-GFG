class Solution {
    public int singleNumber(int[] nums) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int ones = 0;
            for (int num : nums) {
                if ((num & (1 << i)) != 0) {
                    ones++;
                }
            }
            if (ones % 3 != 0) {
                ans |= (1 << i);
            }
        }
        return ans;
    }
}


// class Solution {
//     public int singleNumber(int[] nums) {
//         int ones = 0, twos = 0;
//         for (int num : nums) {
//             ones = (ones ^ num) & ~twos;
//             twos = (twos ^ num) & ~ones;
//         }
//         return ones;
//     }
// }