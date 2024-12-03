class Solution {
public:
    #define ll long long
    const ll MOD = 1e9 + 7;
    // Rabin Karp Algorithm
    ll hashValue(string &s, ll RADIX, ll m) {
        ll ans = 0, factor = 1;
        for (ll i = m - 1; i >= 0; i--) {
            ans = (ans + ((s[i] - 'a') * factor) % MOD) % MOD;
            factor = (factor * RADIX) % MOD;
        }
        return ans % MOD;
    }

    int strStr(string haystack, string needle) {
        ll n = haystack.length(), m = needle.length();
        if (n < m) return -1;
        ll RADIX = 26, MAX_WEIGHT = 1;
        for (ll i = 1; i <= m; i++) {
            MAX_WEIGHT = (MAX_WEIGHT * RADIX) % MOD;
        }

        ll hashNeedle = hashValue(needle, RADIX, m), hashHay = 0;
        for (ll i = 0; i <= n - m; i++) {
            if (i == 0) {
                hashHay = hashValue(haystack, RADIX, m);
            } else {
                hashHay = ((hashHay * RADIX) % MOD - ((haystack[i - 1] - 'a') * MAX_WEIGHT) % MOD + (haystack[i + m - 1] - 'a') + MOD) % MOD;
            }
            if (hashNeedle == hashHay) {
                for (ll j = 0; j < m; j++) {
                    if (needle[j] != haystack[j + i]) break;
                    if (j == m - 1) return i;
                }
            }
        }
        return -1;
    }
};