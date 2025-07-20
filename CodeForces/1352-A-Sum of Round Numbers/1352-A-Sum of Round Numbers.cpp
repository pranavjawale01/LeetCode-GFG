#include<bits/stdc++.h>
using namespace std;

void pranavjawale01() {
    int n;
    cin >> n;
    vector<int> arr;
    int tens = 1;
    while (n > 0) {
        int temp = n % 10;
        if (temp != 0) {
            arr.push_back(temp * tens);
        }
        n /= 10;
        tens *= 10;
    }
    cout << arr.size() << endl;
    for (int x : arr) {
        cout << x << " ";
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
