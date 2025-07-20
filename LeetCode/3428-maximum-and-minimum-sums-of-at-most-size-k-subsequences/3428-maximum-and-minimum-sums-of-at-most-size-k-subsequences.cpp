class Solution {
public:
    #define ll long long
    #define all(x) x.begin(), x.end()
    #define vll vector<ll>
    ll mod = 1e9 + 7;

    ll modpow(ll b, ll e) {
        ll ans = 1;
        while (e) {
            if (e & 1) {
                ans = (ans * b) % mod;
            }
            b = (b * b) % mod;
            e >>= 1;
        }
        return ans;
    }
    
    int minMaxSums(vector<int>& nums, int k) {
        sort(all(nums));
        int n = nums.size();
        vll fact(n+1, 1), invFact(n+1, 1);
        for (ll i = 1; i <= n; i++) {
            fact[i] = (fact[i-1] * i) % mod;
        }
        invFact[n] = modpow(fact[n], mod - 2);
        for (ll i = n - 1; i >= 0; i--) {
            invFact[i] = (invFact[i+1] * (i+1)) % mod;
        }
        function<ll(ll,ll)> counter = [&](ll n, ll r) {
            if (r > n || r < 0) return 0ll;
            return (ll)(fact[n] * invFact[r] % mod) * invFact[n-r] % mod;
        };
        ll ans = 0;
        for (ll i = 0; i < n; i++) {
            for (ll j = 1; j <= k; j++) {
                ll cnt = counter(n-i-1, j-1);
                ans = (ans + nums[i] * cnt) % mod;
            }
            for (ll j = 1; j <= k; j++) {
                ll cnt = counter(i, j-1);
                ans = (ans + nums[i] * cnt) % mod;
            }
        }
        return ans;
    }
};