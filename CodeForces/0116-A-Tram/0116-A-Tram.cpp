#include <bits/stdc++.h>
using namespace std;

void pranavjawale01() {
    int n;
    cin >> n;
    int capacity = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int leave, enter;
        cin >> leave >> enter;
        capacity -= leave;
        capacity += enter;
        ans = max(ans, capacity);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    pranavjawale01();
    return 0;
}
