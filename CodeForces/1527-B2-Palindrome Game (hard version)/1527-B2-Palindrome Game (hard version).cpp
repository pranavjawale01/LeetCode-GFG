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
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

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
    string s;
    cin >> s;
    bool palli = true;
    ll one = 0;
    for (ll i = 0; i < n / 2; i++) {
        if (s[i] != s[n-i-1]) palli = false;
        if ((s[i] == '1' || s[n-i-1] == '1') && s[i] != s[n-i-1]) {
            one++;
        }
    }
    ll zero = 0;
    for (char c : s) {
        if (c == '0') zero++;
    }
    if (palli) {
        if (zero == 1) {
            cout << "BOB" << endl;
        } else if (zero % 2 == 1) {
            cout << "ALICE" << endl;
        } else {
            cout << "BOB" << endl;
        }
    } else {
        if (zero == 2 && one == 1) {
            cout << "DRAW" << endl;
        } else {
            cout << "ALICE" << endl;
        }
    }
}

int main() {
    fast_io();
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--) {
        pranavjawale01();
    }
    return 0;
}
