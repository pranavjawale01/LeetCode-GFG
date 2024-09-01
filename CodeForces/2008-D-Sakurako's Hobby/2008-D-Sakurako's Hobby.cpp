#include <bits/stdc++.h>
using namespace std;

void pranavjawale01() {
    int n;  
    cin >> n;  
    vector<int> p(n);
    vector<int> ans(n, 0);  
    vector<bool> vis(n, false);  
    string s;  

    for (int i = 0; i < n; ++i) {  
        cin >> p[i];  
        p[i]--;   
    }  
    
    cin >> s;  

    for (int i = 0; i < n; ++i) {  
        if (!vis[i]) {  
            vector<int> arr;  
            int countB = 0;  
            int x = i;  
            
            while (!vis[x]) {  
                vis[x] = true;  
                arr.push_back(x);  
                if (s[x] == '0') {  
                    countB++;  
                }  
                x = p[x];  
            }  
            
            for (int idx : arr) {  
                ans[idx] = countB;  
            }  
        }  
    }  

    for (int i = 0; i < n; ++i) {  
        cout << ans[i] << " ";  
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
