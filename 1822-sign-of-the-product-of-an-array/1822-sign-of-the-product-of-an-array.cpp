class Solution {
public:
    int arraySign(vector<int>& nums) {
        int count = 0;
        for (int num : nums) {
            if (num == 0) {
                return 0;
            }
            if (num < 0) {
                count++;
            }
        }
        if (count % 2 == 0) {
            return 1;
        } else {
            return -1;
        }
        return 0;
    }
};