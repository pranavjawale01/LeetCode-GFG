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
    
    vll arr(7);
    input1d(arr);

    ll i = 0;
    
    while (n > 0) {
        n -= arr[i];
        i = (i + 1) % 7;
    }

    cout << (i == 0 ? 7 : i) << endl;
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
