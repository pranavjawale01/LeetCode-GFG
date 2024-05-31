class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int ones = 0, zeros = 0;
            for (int num : nums) {
                if (num & (1 << i)) {
                    ones++;
                } else {
                    zeros++;
                }
            }
            if (ones % 3 != 0) {
                ans |= 1 << i;
            }
        }
        return ans;
    }
};


// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         int ones = 0, twos = 0, threes = 0;
//         for (int num : nums) {
//             twos |= ones & num;
//             ones ^= num;
//             threes = ones & twos;
//             ones &= ~threes;
//             twos &= ~threes;
//         }
//         return ones;
//     }
// };