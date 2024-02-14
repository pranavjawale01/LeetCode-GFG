class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg, output;
        int n = nums.size();
        for (int num : nums) {
            if (num > 0) {
                pos.push_back(num);
            } else {
                neg.push_back(num);
            }
        }
        for (int i = 0; i < n / 2; i++) {
            output.push_back(pos[i]);
            output.push_back(neg[i]);
        }
        return output;
    }
};