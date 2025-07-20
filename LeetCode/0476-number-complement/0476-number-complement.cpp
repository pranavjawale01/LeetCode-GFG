class Solution {
public:
    int findComplement(int num) {
        int i = 31;
        while (i >= 0 && (num & (1 << i)) == 0) {
            i--;
        }
        for (; i >= 0; i--) {
            num = num ^ (1 << i);
        }
        return num;
    }
};