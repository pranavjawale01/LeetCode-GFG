class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int x : nums) mp[x]++;
        priority_queue<pair<int, int>> pq;
        for (auto x : mp) {
            pq.push({x.second, x.first});
        }
        vector<int> ans;
        while (k--) {
            auto [freq, val] = pq.top();
            pq.pop();
            ans.push_back(val);
        }
        return ans;
    }
};