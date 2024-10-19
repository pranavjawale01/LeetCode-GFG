class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        
        for (int i = 2; i <= n; ++i) {
            string inverted = s;
            transform(inverted.begin(), inverted.end(), inverted.begin(), [](char c) { return c == '0' ? '1' : '0'; });
            reverse(inverted.begin(), inverted.end());
            s = s + "1" + inverted;
        }
        
        return s[k - 1];
    }
};