#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define all(x) x.begin(), x.end()
#define pb push_back
#define ff first
#define ss second
#define nl "\n"

const int MOD = 1e9 + 7;
const ll INF = 1e18;
const ld PI = acos(-1.0);

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll mod_exp(ll base, ll exp, ll mod = MOD) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

template<typename T>
void input1d(vector<T> &arr) {
    for (auto &x : arr) cin >> x;
}

template<typename T>
void input2d(vector<vector<T>> &arr) {
    for (auto &row : arr) {
        for (auto &x : row) {
            cin >> x;
        }
    }
}

template<typename T>
void output1d(const vector<T> &arr) {
    for (const auto &x : arr) cout << x << " ";
    cout << endl;
}

template<typename T>
void output2d(const vector<vector<T>> &arr) {
    for (const auto &row : arr) {
        for (const auto &x : row) {
            cout << x << " ";
        }
        cout << endl;
    }
}

//----------------------------------Solution code here-----------------------------//
bool check(ll mid, ll rb, ll rs, ll rc, ll nb, ll ns, ll nc, ll pb, ll ps, ll pc, ll r) {
    ll reqb = rb * mid - nb;
    ll reqs = rs * mid - ns;
    ll reqc = rc * mid - nc;
    if (reqb < 0) reqb = 0;
    if (reqs < 0) reqs = 0;
    if (reqc < 0) reqc = 0;
    ll reqMoneyB = reqb * pb;
    ll reqMoneyS = reqs * ps;
    ll reqMoneyC = reqc * pc;
    ll moneyReq = reqMoneyB + reqMoneyS + reqMoneyC;
    if (moneyReq > r) {
        return false;
    }
    return true;
}

void pranavjawale01() {
    string s;
    cin >> s;
    ll nb, ns, nc;
    cin >> nb >> ns >> nc;
    ll pb, ps, pc;
    cin >> pb >> ps >> pc;
    ll money;
    cin >> money;
    ll ans = 0;
    ll low = 0, high = 1e14;
    ll rb = 0, rs = 0, rc = 0;
    for (char &c : s) {
        if (c == 'B') rb++;
        if (c == 'S') rs++;
        if (c == 'C') rc++;
    }
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (check(mid, rb, rs, rc, nb, ns, nc, pb, ps, pc, money)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans << endl;
}

int main() {
    fast_io();
    int t = 1;
    //cin >> t;
    while (t--) {
        pranavjawale01();
    }
    return 0;
}
