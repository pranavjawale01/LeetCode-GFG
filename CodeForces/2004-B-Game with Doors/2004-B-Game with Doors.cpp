#include<bits/stdc++.h>
using namespace std;

void pranavjawale01() {
    int al, ar; 
    cin >> al >> ar;
    int bl, br; 
    cin >> bl >> br;
    
    vector<int> arr(105, 0);
    
    int door = min(ar, br) - max(al, bl);
    
    if (al < bl) {
        arr[bl - 1] = true;
    }
    if (bl < al) {
        arr[al - 1] = true;
    }
    if (br > ar) {
        arr[ar] = true;
    }
    if (ar > br) {
        arr[br] = true;
    }

    int ans = 0;
    for (int i = 1; i <= 101; i++) {
        ans += arr[i];
    }

    if (door < 0) ans = 0;

    cout << max(1, ans + max(0, min(ar, br) - max(al, bl))) << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        pranavjawale01();
    }   
    return 0;
}
