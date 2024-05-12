class Solution {
public:
    int arraySign(vector<int>& nums) {
        int pro = 1;
        for (int num : nums) {
            pro *= num;
        }
        if (pro > 0) {
            return 1;
        } else if (pro < 0) {
            return -1;
        }
        return 0;
    }
};