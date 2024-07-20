#include <iostream>
#include <map>
using namespace std;

#define nl '\n'
typedef long long ll;

void inputArray(ll n, ll arr[]) {
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

ll sumOfArray(ll n, ll arr[]) {
    ll sum = 0;
    for(ll i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

void solve() {
    ll n;
    cin >> n;

    ll arr[n];
    inputArray(n, arr);

    map<ll, ll> frequencyMap;
    ll maxElement = 0;

    ll totalSum = sumOfArray(n, arr);
    for(ll i = 0; i < n; i++) {
        frequencyMap[arr[i]]++;
        if(frequencyMap[arr[i]] >= 2) {
            if(arr[i] > maxElement) maxElement = arr[i];
        }
        arr[i] = maxElement;
    }

    frequencyMap.clear();
    for(ll i = 0; i < n; i++) frequencyMap[arr[i]]++;

    ll prevElement = 0;
    ll duplicateElement = 0;
    for(ll i = 0; i < n; i++) {
        if(arr[i] != prevElement) {
            totalSum += arr[i];
            if(frequencyMap[arr[i]] == 1) totalSum += (n - i - 1) * duplicateElement;
            else {
                totalSum += (n - i - 1) * arr[i];
                duplicateElement = arr[i];
            }
        }
    }

    cout << totalSum << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
