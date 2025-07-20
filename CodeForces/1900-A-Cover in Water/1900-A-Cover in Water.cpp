#include <bits/stdc++.h>
using namespace std;

void pranavjawlae01() {
    int n;
    cin >> n;
    vector<char> arr(n);
    int dotCount = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] == '.') {
            dotCount++;
        }
    }

    for (int i = 0; i < n - 2; i++) {
        if (arr[i] == '.' && arr[i + 1] == '.' && arr[i + 2] == '.') {
            cout << 2 << endl;
            return;
        }
    }

    cout << dotCount << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        pranavjawlae01();
    }
    return 0;
}
