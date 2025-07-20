#include <bits/stdc++.h>
using namespace std;

void pranavjawale01() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> brr;
    brr.push_back(arr[0]);
    for (int i = 1; i < n; i++) {
        if (arr[i-1] > arr[i]) {
            brr.push_back(arr[i]);
            brr.push_back(arr[i]);
        } else {
            brr.push_back(arr[i]);
        }
    }
    cout << brr.size() << endl;
    for (int i = 0; i < brr.size(); i++) {
        cout << brr[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        pranavjawale01();
    }
    return 0;
}
