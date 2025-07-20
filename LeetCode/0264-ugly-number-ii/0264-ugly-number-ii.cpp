class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n+1);
        dp[1] = 1;
        int i2, i3, i5;
        i2 = i3 = i5 = 1;
        for (int i = 2; i <= n; i++) {
            int i2th_ugly = dp[i2] * 2;
            int i3th_ugly = dp[i3] * 3;
            int i5th_ugly = dp[i5] * 5;
            dp[i] = min({i2th_ugly, i3th_ugly, i5th_ugly});
            if (dp[i] == i2th_ugly) {
                i2++;
            }
            if (dp[i] == i3th_ugly) {
                i3++;
            }
            if (dp[i] == i5th_ugly) {
                i5++;
            }
        }
        return dp[n];
    }
};





// TLE
// class Solution {
// public:
//     unordered_map<int, bool> mp;
//     bool isUgly(int n) {
//         if (n <= 0) {
//             return false;
//         }
//         if (n == 1) {
//             return true;
//         }
//         if (mp.find(n) != mp.end()) {
//             return mp[n];
//         }
//         if (n % 2 == 0 && isUgly(n / 2)) {
//             return mp[n] = true;
//         }
//         if (n % 3 == 0 && isUgly(n / 3)) {
//             return mp[n] = true;
//         }
//         if (n % 5 == 0 && isUgly(n / 5)) {
//             return mp[n] = true;
//         }
//         return mp[n] = false;
//     }
//     int nthUglyNumber(int n) {
//         mp.clear();
//         int num = 1;
//         while (n > 0) {
//             if (isUgly(num)) {
//                 n--;
//             }
//             num++;
//         }
//         return num - 1;
//     }
// };