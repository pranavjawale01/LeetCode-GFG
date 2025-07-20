class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != 0) {
                swap(nums[j], nums[i]);
                i++;
            }
        }
    }
};


// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int k = 0;
//         int count = 0;
//         int n = nums.size();
//         for (int i = 0; i < n; i++) {
//             if (nums[i] == 0) {
//                 count++;
//             } else {
//                 nums[k++] = nums[i];
//             }
//         }
//         for (int i = n - count; i < n; i++) {
//             nums[i] = 0;
//         }
//     }
// };