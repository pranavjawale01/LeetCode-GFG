class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxE = *max_element(begin(nums), end(nums));
        int n = nums.size(), i = 0, j = 0;
        long long result = 0;
        int countMax = 0;
        while (j < n) {
            if (nums[j] == maxE) {
                countMax++;
            }
            while (countMax >= k) {
                result += n - j;
                if (nums[i] == maxE) {
                    countMax--;
                }
                i++;
            }
            j++;
        }
        return result;
    }
};