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
#define yes cout << "YES"
#define no cout << "NO"

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
ll n, x1, y11, x[200010], y[200010];
string s;

bool solve(ll len) {
    for (ll l = 1, r = len; r <= n; l++, r++) {
        ll dx = x[n] - (x[r] - x[l-1]);
        ll dy = y[n] - (y[r] - y[l-1]);
        ll distance = abs(dx - x1) + abs(dy - y11);
        if (len >= distance && (len - distance) % 2 == 0) {
            return true;
        }
    }
    return false;
}

void pranavjawale01() {
    cin >> n >> s >> x1 >> y11;
    for (ll i = 1; i <= n; i++) {
        x[i] = x[i-1];
        y[i] = y[i-1];
        if (s[i-1] == 'U') y[i]++;
        if (s[i-1] == 'D') y[i]--;
        if (s[i-1] == 'R') x[i]++;
        if (s[i-1] == 'L') x[i]--;
    }
    ll low = 0, high = n, ans = -1;
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (solve(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
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
