class Solution {
public:
    const long long mod = 1e9 + 7;
    long long binpow(long long x, long long y) {
        long long ans = 1;
        while (y) {
            if (y & 1) {
                ans = (ans * x) % mod;
            }
            x = (x * x) % mod;
            y >>= 1;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n / 2;
        long long first = (binpow(5, even)) % mod;
        long long second = (binpow(4, odd)) % mod;
        return (int) ((first * second) % mod);
    }
};