class Solution {
public:
    typedef long long ll;
    long long wonderfulSubstrings(string word) {
        ll ans = 0;
        unordered_map<ll, ll> mp;
        mp[0] = 1;
        int cum_xor = 0;
        for (char &ch : word) {
            int shift = ch - 'a';
            cum_xor ^= (1 << shift);
            ans += mp[cum_xor];
            for (char ch1 = 'a'; ch1 <= 'j'; ch1++) {
                shift = ch1 - 'a';
                ll check_xor = (cum_xor ^ (1 << shift));
                ans += mp[check_xor];
            }
            mp[cum_xor]++;
        }
        return ans;
    }
};