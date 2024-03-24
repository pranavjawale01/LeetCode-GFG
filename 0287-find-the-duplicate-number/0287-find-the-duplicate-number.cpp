class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int &num : nums) {
            if (mp[num] == 0) {
                mp[num]++;
            } else {
                return num;
            }
        }
        return -1;
    }
};