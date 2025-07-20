class Solution {
    public double myPow(double x, int n) {
        if (n == Integer.MIN_VALUE) {
            x = x * x;
            n = n / 2;
        }

        if (n < 0) {
            n *= -1;
            x = 1 / x;
        }

        double res = 1;

        while (n > 0) {
            if ((n & 1) == 1) {
                res *= x;
            } 
            n = n >> 1;
            x *= x;
        }

        return res;
    }
}