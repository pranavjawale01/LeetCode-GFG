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

void pranavjawale01() {
    string s, t;
    cin >> s >> t;
    unordered_map<char, int> mp1, mp2;
    
    for (char &c : s) mp1[c]++;
    for (char &c : t) mp2[c]++;
    
    ll n = s.size(), m = t.size();
    ll i = 0, j = 0;
    
    while (i < n && j < m) {
        if (s[i] == t[j]) {
            if (mp1[s[i]] < mp2[t[j]]) {
                break;
            }
            if (mp1[s[i]] == mp2[t[j]]) {
                mp2[t[j]]--;
                j++;
            }
        }
        mp1[s[i]]--;
        i++;
    }
    
    if (j == m) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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
