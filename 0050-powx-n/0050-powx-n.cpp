class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long temp = n;
        if (temp < 0) {
            temp = temp * -1;
        }
        while (temp) {
            if (temp % 2) {
                ans = ans * x;
                temp = temp - 1;
            } else {
                x = x * x;
                temp = temp / 2;
            }
        }
        if (n < 0) {
            ans = 1.0 / ans;
        }
        return ans;
    }
};