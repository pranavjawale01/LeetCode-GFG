class Solution {
public:
    #define all(x) x.begin(), x.end()
    #define ll long long
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        if (arr == brr) return 0;
        int n = arr.size();
        if (n == 1) return abs(arr[0] - brr[0]);
        ll ans2 = 0;
        for (ll i = 0; i < n; i++) {
            ans2 += abs(arr[i] - brr[i]);
        }
        sort(all(arr));
        sort(all(brr));
        ll ans1 = k;        
        for (ll i = 0; i < n; i++) {
            ans1 += abs(arr[i] - brr[i]);
        }
        return min(ans1, ans2);
    }
};