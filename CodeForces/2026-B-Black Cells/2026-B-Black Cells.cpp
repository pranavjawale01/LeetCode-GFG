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
#define endl "\n"
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
void pranavjawale01() {
    ll n;
    cin >> n;
    vll arr(n);
    input1d(arr);
    sort(all(arr));
    if (n == 1) {
        cout << 1 << endl;
    } else if (n % 2 == 0) {
        ll ansk = arr[1] - arr[0];
        for (int i = 2; i < n; i += 2) {
            ansk = max(ansk, arr[i+1] - arr[i]);
        }
        cout << ansk << endl;
    } else {
        ll ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            vll v;
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                v.pb(arr[j]);
            }
            ll mx = v[1] - v[0];
            for (int j = 2; j < n - 1; j += 2) {
                mx = max(mx, v[j+1] - v[j]);
            }
            ans = min(ans, mx);
        }
        cout << ans << endl;
    }
}

int main() {
    fast_io();
    int t = 1;
    cin >> t;
    while (t--) {
        pranavjawale01();
    }
    return 0;
}
