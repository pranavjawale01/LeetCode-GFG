class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int numOfSetBits = __builtin_popcount(nums[0]);
        int maxOfSegment = nums[0];
        int minOfSegment = nums[0];

        int maxOfPrevSegment = INT_MIN;

        for (int i = 1; i < nums.size(); i++) {
            if (__builtin_popcount(nums[i]) == numOfSetBits) {
                maxOfSegment = max(maxOfSegment, nums[i]);
                minOfSegment = min(minOfSegment, nums[i]);
            } else {
                if (minOfSegment < maxOfPrevSegment) {
                    return false;
                }

                maxOfPrevSegment = maxOfSegment;

                maxOfSegment = nums[i];
                minOfSegment = nums[i];
                numOfSetBits = __builtin_popcount(nums[i]);
            }
        }
        if (minOfSegment < maxOfPrevSegment) {
            return false;
        }
        return true;
    }
};





// class Solution {
// public:
//     bool canSortArray(vector<int>& nums) {
//         int n = nums.size();
//         bool swapped = true;
//         for (int i = 0; i < n; i++) {
//             swapped = false;
//             for (int j = 0; j < n - i - 1; j++) {
//                 if (nums[j] <= nums[j+1]) {
//                     continue;
//                 } else {
//                     if (__builtin_popcount(nums[j]) == __builtin_popcount(nums[j+1])) {
//                         swap(nums[j], nums[j+1]);
//                         swapped = true;
//                     } else {
//                         return false;
//                     }
//                 }
//             }
//             if (!swapped) {
//                 break;
//             }
//         }
//         return true;
//     }
// };