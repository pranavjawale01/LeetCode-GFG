class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> mp;
        for (int x : nums) {
            mp[x]++;
        }
        auto cmp = [&](int a, int b) {
            if (mp[a] == mp[b]) {
                return b < a;
            }
            return mp[a] < mp[b];
        };
        sort(nums.begin(), nums.end(), cmp);
        return nums;
    }
};