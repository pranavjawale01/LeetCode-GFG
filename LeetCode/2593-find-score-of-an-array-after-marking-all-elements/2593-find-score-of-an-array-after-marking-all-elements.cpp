class Solution {
public:
    #define ll long long
    long long findScore(vector<int>& nums) {
        ll ans = 0;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }
        int n = nums.size();
        vector<bool> vis(n, false);
        while (!pq.empty()) {
            ll val = pq.top().first;
            ll idx = pq.top().second;
            pq.pop();
            if (vis[idx]) continue;
            ans += val;
            vis[idx] = true;
            if (idx - 1 >= 0) vis[idx - 1] = true;
            if (idx + 1 < n) vis[idx + 1] = true;
        }
        return ans;
    }
};