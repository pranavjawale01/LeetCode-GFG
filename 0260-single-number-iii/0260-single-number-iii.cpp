class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if (nums.size() == 2) {
            return nums;
        }
        int ans = 0;
        for (int num : nums) {
            ans ^= num;
        }
        int bit = 0;
        for (int i = 31; i >= 0; i--) {
            if (ans & 1 << i) {
                bit = i;
                break;
            }
        }
        int a = 0, b = 0;
        for (int num : nums) {
            if (num & 1 << bit) {
                a ^= num;
            } else {
                b ^= num;
            }
        }
        return {a, b};
    }
};