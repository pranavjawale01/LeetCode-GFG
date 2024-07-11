#include<bits/stdc++.h>
using namespace std;

int main() {
    
    int t; 
    cin >> t;
    
    while (t--) {
        long long n, k;
        cin >> n >> k;
        long long arr[k];
        for (long long i = 0; i < k; i++) {
            cin >> arr[i];
        }
        long long ans = 0;
        sort(arr, arr + k);
        for (long long i = 0; i < k - 1; i++) {
            ans += 2 * arr[i] - 1;
        }
        cout << ans << endl;
    }
    
    return 0;
}
