class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int> mp;
        for (int x : nums) {
            if (x % 2 == 0) {
                mp[x]++;
            }
        }
        int ans = -1, count = 0;
        for (auto x : mp) {
            if (x.second > count) {
                count = x.second;
                ans = x.first;
            }
        }
        return ans;
    }
};