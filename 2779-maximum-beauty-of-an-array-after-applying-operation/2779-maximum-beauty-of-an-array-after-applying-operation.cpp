class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        vector<pair<int, int>> ranges;
        for (int x : nums) {
            ranges.push_back({x-k, x+k});
        }
        sort(ranges.begin(), ranges.end());
        int maxBeauty = 0;
        deque<int> dq;
        for (auto &x : ranges) {
            while (!dq.empty() && dq.front() < x.first) {
                dq.pop_front();
            }
            dq.push_back(x.second);
            maxBeauty = max(maxBeauty, (int)dq.size());
        }
        return maxBeauty;
    }
};