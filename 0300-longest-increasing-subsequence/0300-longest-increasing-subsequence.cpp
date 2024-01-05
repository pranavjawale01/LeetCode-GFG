class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails(nums.size(), 0);
        int size = 0;
        for (int x : nums) {
            int i = 0, j = size;
            while (i != j) {
                int n = (i + j) / 2;
                if (tails[n] < x) {
                    i = n + 1;
                } else {
                    j = n;
                }
            }
            tails[i] = x;
            if (i == size) {
                size++;
            }
        }
        return size;
    }
};