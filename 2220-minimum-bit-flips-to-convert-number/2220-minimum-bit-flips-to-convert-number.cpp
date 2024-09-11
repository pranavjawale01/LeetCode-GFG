class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = start ^ goal;
        int count = 0;
        while (ans) {
            if (ans & 1) {
                count++;
            }
            ans >>= 1;
        }
        return count;
    }
};




// class Solution {
// public:
//     int minBitFlips(int start, int goal) {
//         int ans = start ^ goal;
//         return __builtin_popcount(ans);
//     }
// };




// class Solution {
// public:
//     int minBitFlips(int start, int goal) {
//         int count = 0;
//         for (int i = 0; i < 32; i++) {
//             int bit1 = start & 1;
//             int bit2 = goal  & 1;
//             start >>= 1;
//             goal  >>= 1;
//             if (bit1 != bit2) {
//                 count++;
//             }
//         }
//         return count;
//     }
// };