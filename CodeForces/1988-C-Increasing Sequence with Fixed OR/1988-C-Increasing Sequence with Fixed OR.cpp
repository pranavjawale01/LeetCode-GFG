#include <bits/stdc++.h>
using namespace std;

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void printArr(long long n, vector<long long>& arr) {
    for (long long i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

long long sumOfArr(long long n, long long bits[]) {
    long long ans = 0;
    for (long long i = 0; i < n; i++) ans += bits[i];
    return ans;
}

long long findNum(long long n, long long bits[]) {
    long long ans = 0;
    long long i = 0;
    for (long long i = 0; i < 64; i++) {
        if (bits[i] == 1 && i != n) {
            ans += binpow(2L, i);
        }
    }
    return ans;
}

void solve() {
    long long n;
    cin >> n;

    if ((n & (n - 1)) == 0) {
        cout << "1" << endl;
        cout << n << endl;
        return;
    }

    long long bits[64] = {0};
    long long temp = n;
    long long p = 0;

    vector<long long> ans;
    ans.push_back(n);

    while (temp > 0) {
        if (temp % 2 != 0) {
            bits[p]++;
        }
        p++;
        temp /= 2;
    }

    long long sum = sumOfArr(64, bits);

    cout << sum + 1 << endl;

    for (int i = 0; i < 64; i++) {
        if (bits[i] == 1) {
            ans.push_back(findNum(i, bits));
        }
    }

    reverse(ans.begin(), ans.end());
    printArr(sum + 1, ans);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
