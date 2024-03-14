class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int count   = 0;
        int currSum = 0;
        mp[0] = 1;
        for(int &num : nums) {
            currSum += num;
            if (mp.find(currSum - goal) != mp.end()) {
                count += mp[currSum - goal];
            }            
            mp[currSum]++;          
        }        
        return count;
    }
};