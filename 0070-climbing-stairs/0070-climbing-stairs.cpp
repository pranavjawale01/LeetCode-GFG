class Solution {
public:
    int t[46];
    int recursive(int n) {
        if (n < 0) {
            return 0;
        }
        if (t[n] != -1) {
            return t[n];
        }
        if (n == 0) {
            return 1;
        }
        int oneStep = recursive(n - 1);
        int twoStep = recursive(n - 2);
        return t[n] = oneStep + twoStep;
    }
    int climbStairs(int n) {
        memset(t, -1, sizeof(t));
        return recursive(n);
    }
};