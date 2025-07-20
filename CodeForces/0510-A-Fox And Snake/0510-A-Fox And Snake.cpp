#include <bits/stdc++.h>
using namespace std;

void pranavjawale01() {
    int row, col;
    cin >> row >> col;
    vector<vector<char>> arr(row, vector<char>(col, '#'));
    bool flag = true;

    for (int i = 1; i < row; i += 2) {
        if (flag) {
            for (int j = 0; j < col - 1; j++) {
                arr[i][j] = '.';
            }
        } else {
            for (int j = 1; j < col; j++) {
                arr[i][j] = '.';
            }
        }
        flag = !flag;
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    pranavjawale01();
    return 0;
}
