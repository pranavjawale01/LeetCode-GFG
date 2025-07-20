class Solution {
    long mod = 1000000000 + 7;
    long binpow(long x, long y) {
        long ans = 1;
        while (y > 0) {
            if ((y & 1) == 1) {
                ans = (ans * x) % mod;
            }
            x = (x * x) % mod;
            y >>= 1;
        }
        return ans;
    }
    public int countGoodNumbers(long n) {
        long even = (n + 1) / 2;
        long odd = n / 2;
        long first = binpow(5, even) % mod;
        long second = binpow(4, odd) % mod;
        return (int)((first * second) % mod);
    }
}