class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx = -1;
        int n = nums.size();
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] > nums[i-1]) {
                idx = i-1;
                break;
            }
        }
        if (idx != -1) {
            int swap_idx = idx;
            for (int i = n - 1; i >= idx; i--) {
                if (nums[i] > nums[idx]) {
                    swap_idx = i;
                    break;
                }
            }
            swap(nums[swap_idx], nums[idx]);
            reverse(nums.begin() + idx + 1, nums.end());
        } else {
            reverse(nums.begin(), nums.end());
        }
    }
};





// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         next_permutation(nums.begin(), nums.end());
//     }
// };