class Solution {
public:
    int ans, l, h, z, o;
    int m = 1e9 + 7;
    vector<int> dp;

    int solve(int L) {
        if (L > h) return 0;
        if (dp[L] != -1) return dp[L];
        bool addOne = false;
        if (l <= L && L <= h) addOne = true;
        int take_zero = solve(L + z);
        int take_one  = solve(L + o);
        return dp[L] = (addOne + take_zero + take_one) % m;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        ans = 0;
        l = low;
        h = high;
        z = zero;
        o = one;
        dp.resize(h+1, -1);
        return solve(0);
    }
};