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

//----------------------------------Solution code here-----------------------------//
void toggle(vector<vector<int>>& grid, int i, int j) {
    if (i >= 0 && i < 3 && j >= 0 && j < 3) {
        grid[i][j] = 1 - grid[i][j];
    }
}

void pranavjawale01() {
    vector<vector<int>> grid(3, vector<int>(3, 1));
    vector<vector<int>> presses(3, vector<int>(3, 0));

    input2d(presses);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (presses[i][j] % 2 != 0) {
                toggle(grid, i, j);
                toggle(grid, i - 1, j);   // Toggle above
                toggle(grid, i + 1, j);   // Toggle below
                toggle(grid, i, j - 1);   // Toggle left
                toggle(grid, i, j + 1);   // Toggle right
            }
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << grid[i][j];
        }
        cout << endl;
    }
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
