#include <bits/stdc++.h>
using namespace std;

void pranavjawale01() {
    string s;
    cin >> s;
    int freq[26] = {0};
    int distinctCount = 0;

    for (char &c : s) {
        freq[c - 'a']++;
    }
    
    for (int i = 0; i < 26; i++) {
        if (freq[i] >= 1) {
            distinctCount++;
        }
    }

    if (distinctCount % 2 == 0) {
        cout << "CHAT WITH HER!" << endl;
    } else {
        cout << "IGNORE HIM!" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    pranavjawale01();
    return 0;
}
