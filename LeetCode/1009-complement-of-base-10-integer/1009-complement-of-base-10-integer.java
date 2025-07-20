class Solution {
    public int bitwiseComplement(int n) {
        if (n == 0) return 1;
        
        int i = 31;
        while (i >= 0 && (n & (1 << i)) == 0) {
            i--;
        }
        for (; i >= 0; i--) {
            n = n ^ (1 << i);
        }
        return n;
    }
}