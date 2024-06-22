class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int odd = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] % 2 != 0) {
                    odd++;
                }
                if (odd == k) {
                    count++;
                }
            }
        }
        return count;
    }
};