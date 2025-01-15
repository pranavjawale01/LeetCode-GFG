class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int count = 0;
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            if (num2 & 1 << i) {
                count++;
            }
        }
        for (int i = 31; i >= 0 && count > 0; i--) {
            if ((1 << i) & num1) {
                count--;
                ans = ans | 1 << i;
            }
        }
        for (int i = 0; i < 32 && count > 0; i++) {
            if ((1 << i & ans) == 0) {
                ans = ans | 1 << i;
                count--;
            }
        }
        return ans;
    }
};