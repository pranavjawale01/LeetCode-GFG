class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1) {
            return '0';
        }
        int len = pow(2, n) - 1; // (1 << n) - 1
        if (k < ceil(len / 2.0)) {
            return findKthBit(n-1, k);
        } else if (k == ceil(len / 2.0)) {
            return '1';
        } else {
            char ch = findKthBit(n-1, len - (k-1));
            return (ch == '0') ? '1' : '0';
        }
    }
};










// class Solution {
// public:
//     char findKthBit(int n, int k) {
//         string s = "0";
        
//         for (int i = 2; i <= n; ++i) {
//             string inverted = s;
//             transform(inverted.begin(), inverted.end(), inverted.begin(), [](char c) { return c == '0' ? '1' : '0'; });
//             reverse(inverted.begin(), inverted.end());
//             s = s + "1" + inverted;
//         }
        
//         return s[k - 1];
//     }
// };