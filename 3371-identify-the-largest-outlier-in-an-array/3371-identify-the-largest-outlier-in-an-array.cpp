class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        unordered_map<int, int> mp;
        for (int &x : nums) mp[x]++;        
        int ans = INT_MIN;
        for (int &x : nums) {
            mp[x]--;
            if (mp[x] == 0) {
                mp.erase(x);
            }            
            int rem = totalSum - x;
            if ((rem % 2 == 0) && mp.count(rem / 2)) {
                ans = max(ans, x);
            }
            mp[x]++;
        }        
        return ans;
    }
};