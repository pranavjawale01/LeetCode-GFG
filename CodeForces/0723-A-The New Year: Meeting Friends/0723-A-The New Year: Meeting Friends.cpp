#include<bits/stdc++.h>
using namespace std;

void pranavjawale01() {
    vector<int> ans(3);
    cin >> ans[0] >> ans[1] >> ans[2];
    sort(ans.begin(), ans.end());
    cout << abs(ans[1] - ans[0]) + abs(ans[1] - ans[2]) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    pranavjawale01();
    return 0;
}
