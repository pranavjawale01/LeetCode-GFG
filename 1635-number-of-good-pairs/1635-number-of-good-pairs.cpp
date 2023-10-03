class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int result = 0;
        unordered_map<int,int> count;
        for(int x: nums)
        {
            result += count[x]++;
        }
        return result;
    }
};