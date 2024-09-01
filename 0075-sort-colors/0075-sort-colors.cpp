class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, i = 0;

        while (i <= high) {
            if (nums[i] == 0) {
                swap(nums[i], nums[low]);
                low++;
                i++;
            } else if (nums[i] == 2) {
                swap(nums[i], nums[high]);
                high--;
            } else {
                i++;
            }
        }
    }
};



// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int count[3] = {0};
//         for (int num : nums) {
//             if (num == 0) {
//                 count[0]++;
//             } else if (num == 1) {
//                 count[1]++;
//             } else {
//                 count[2]++;
//             }
//         }
//         for (int i = 0, j = 0; i < 3; i++) {
//             while (count[i] > 0) {
//                 nums[j] = i;
//                 j++;
//                 count[i]--;
//             }
//         }
//     }
// };