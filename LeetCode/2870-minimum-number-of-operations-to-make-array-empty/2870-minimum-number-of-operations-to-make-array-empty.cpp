class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        int total = 0;
        for (auto c: count) {
            if (c.second == 1) {
                return -1;
            }
            total += ceil((double)(c.second) / 3);
        }
        return total;
    }
};