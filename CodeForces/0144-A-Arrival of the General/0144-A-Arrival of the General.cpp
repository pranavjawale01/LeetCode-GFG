#include <bits/stdc++.h>
using namespace std;

void pranavjawale01() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int max_value = 0, min_value = 110;
    int max_i = 0, min_i = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
            max_i = i;
        }
        if (arr[i] <= min_value) {
            min_value = arr[i];
            min_i = i;
        }
    }

    if (max_i > min_i) {
        cout << max_i + (n - 1 - min_i) - 1 << endl;
    } else {
        cout << max_i + (n - 1 - min_i) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        pranavjawale01();
    }
    return 0;
}
