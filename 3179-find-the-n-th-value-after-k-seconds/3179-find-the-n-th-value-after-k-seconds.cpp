class Solution {
public:
    int MOD = 1000000007;
    int valueAfterKSeconds(int n, int k) {
        int a[n];
        for (int i = 0; i < n; i++) {
            a[i] = 1;
        }
        for (int sec = 0; sec < k; sec++) {
            int newK[n];
            newK[0] = a[0];
            for (int i = 1; i < n; i++) {
                newK[i] = (newK[i-1] + a[i]) % MOD;
            }
            for (int i = 0; i < n; i++) {
                a[i] = newK[i];
            }
        }
        return a[n-1];
    }
};