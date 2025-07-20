#include<bits/stdc++.h>
using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;

    if (k == 0) {
        cout << 0 << endl;
        return;
    }

    long long count = 0;
    long long temp = n;
    if (k >= temp) {
        count++;
        k -= temp;
        temp--;
    }

    while (temp > 0 && k > 0) {
        if (k > temp) {
            count++;
            k -= temp;
        }
        if (k > temp) {
            count++;
            k -= temp;
        } else if (k <= temp) {
            count++;
            k = 0;
            break;
        }
        temp--;
    }

    cout << count << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
