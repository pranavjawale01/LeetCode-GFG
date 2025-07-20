class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int currSum = 0;
        int result = 0;
        mp[0] = -1;
        for (int i = 0; i < n; i++) {
            currSum += (nums[i] == 1) ? 1 : -1;
            if (mp.find(currSum) != mp.end()) {
                result = max(result, i - mp[currSum]);
            } else {
                mp[currSum] = i;
            }
        }
        return result;
    }
};