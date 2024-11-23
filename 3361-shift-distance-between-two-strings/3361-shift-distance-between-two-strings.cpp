class Solution {
public:
    #define ll long long
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        ll n = s.size();
        ll ans = 0;
        for (ll i = 0; i < n; i++) {
            ll start = s[i] - 'a', end = t[i] - 'a';
            ll fs = (end - start + 26) % 26;
            ll front = 0;
            for (ll j = 0; j < fs; j++) {
                ll x = (start + j) % 26;
                front += nextCost[x];
            }
            ll bs = (start - end + 26) % 26;
            ll back = 0;
            for (ll j = 0; j < bs; j++) {
                ll x = (start - j + 26) % 26;
                back += previousCost[x];
            }            
            ans += min(front, back);
        }
        return ans;
    }
};