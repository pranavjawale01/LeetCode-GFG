#include<bits/stdc++.h>
using namespace std;

void pranavjawale01() {
    vector<vector<int>> arr(5, vector<int>(5, 0));
    int a, b;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                a = i;
                b = j;
            }
        }
    }
    int count = abs(2 - a) + abs(2 - b);
    cout << count << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    pranavjawale01();
    return 0;
}
