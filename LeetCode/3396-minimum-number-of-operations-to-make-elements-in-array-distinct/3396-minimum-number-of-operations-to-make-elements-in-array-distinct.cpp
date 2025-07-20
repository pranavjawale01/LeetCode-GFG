class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int x : nums) mp[x]++;
        if (mp.size() == n) return 0;
        int ans = 0;
        while (!nums.empty()) {
            for (int i = 0; i < 3 && !nums.empty(); i++) {
                mp[nums[0]]--;
                if (mp[nums[0]] == 0) {
                    mp.erase(nums[0]);
                }
                nums.erase(nums.begin());
            }
            ans++;
            if (mp.size() == nums.size()) break;
        }
        return ans;
    }
};