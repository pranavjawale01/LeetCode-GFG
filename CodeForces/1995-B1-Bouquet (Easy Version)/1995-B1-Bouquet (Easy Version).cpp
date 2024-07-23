#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    long long m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
        
    long long maxPetals = 0;
    long long currentPetals = 0;
    long long currentCost = 0;
        
    int left = 0;
    for (int right = 0; right < n; ++right) {
        currentPetals += a[right];
        currentCost += a[right];
            
        while (left < right && (a[right] - a[left] > 1 || currentCost > m)) {
            currentPetals -= a[left];
            currentCost -= a[left];
            ++left;
        }
            
        if (currentCost <= m) {
            maxPetals = max(maxPetals, currentPetals);
        }
    }
        
    cout << maxPetals << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
