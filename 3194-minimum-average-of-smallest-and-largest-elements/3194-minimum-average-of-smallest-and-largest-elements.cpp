class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        double minEl = INT_MAX;
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        while (i <= j) {
            double avg = (double) (nums[i] + nums[j]) / 2;
            minEl = min(minEl, avg);
            i++;
            j--;
        }
        return minEl;
    }
};