public class Solution {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        int reversed = 0;
        int bitLength = 32;
        for (int i = 0; i < bitLength; ++i) {
            reversed = (reversed << 1) | (n & 1);
            n >>>= 1;
        }
        return reversed;
    }
}