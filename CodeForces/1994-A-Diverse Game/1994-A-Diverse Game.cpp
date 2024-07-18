#include<bits/stdc++.h>
using namespace std;

void solve() {
    int row, col;
    cin >> row >> col;
    vector<vector<int>> arr(row, vector<int>(col, 0));
    vector<vector<int>> brr(row, vector<int>(col, 0));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> arr[i][j];
            brr[i][j] = arr[i][j];
        }
    }
    for (int i = 1; i < row; i++) {
        swap(arr[i], arr[i-1]);
    }
    for (int i = 0; i < row; i++) {
        int temp = arr[i][0];
        for (int j = 0; j < col - 1; j++) {
            arr[i][j] = arr[i][j+1];
        }
        arr[i][col-1] = temp; 
    }
    if (arr == brr) {
        cout << "-1" << endl;
        return;
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
