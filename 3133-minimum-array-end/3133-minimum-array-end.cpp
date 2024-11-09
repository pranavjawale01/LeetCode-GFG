class Solution {
public:
    long long minEnd(int n, int x) {
        n--;
        vector<int> xBit(64, 0), nBit(64, 0);
        for (int i = 0; i < 32; i++) {
            xBit[i] = (x >> i) & 1;
            nBit[i] = (n >> i) & 1;
        }
        for (int i = 0, j = 0; i < 64 && j < 32; i++) {
            if (xBit[i] == 0) {
                xBit[i] = nBit[j++];
            }
        }
        long long ans = 0;
        for (int i = 0; i < 64; i++) {
            ans |= (static_cast<long long>(xBit[i]) << i);
        }
        return ans;
    }
};





// class Solution {
// public:
//     long long minEnd(int n, int x) {
//         long long num = x;
//         for (int i = 1; i < n; i++) {
//             num = (num + 1) | x;
//         }
//         return num;
//     }
// };