class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int minE = *min_element(nums.begin(), nums.end());
        int maxE = *max_element(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        for (auto &x : nums) {
            mp[x]++;
        }
        int j = 0;
        for (int i = minE; i <= maxE; i++) {
            while (mp[i] > 0) {
                nums[j] = i;
                j++;
                mp[i]--;
            }
        }
        return nums;
    }
};