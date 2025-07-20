class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int totalOnes = accumulate(nums.begin(), nums.end(), 0);
        int i = 0, j = 0;
        int currOnes = 0, maxCount = 0;
        while (j < 2 * n) {
            if (nums[j%n] == 1) {
                currOnes++;
            }
            if (j - i + 1 > totalOnes) {
                currOnes -= nums[i%n];
                i++;
            }
            maxCount = max(maxCount, currOnes);
            j++;
        }
        return totalOnes - maxCount;
    }
};





// class Solution {
// public:
//     int minSwaps(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> temp(2*n);
//         for (int i = 0; i < 2 * n; i++) {
//             temp[i] = nums[i % n];
//         }
//         int totalOnes = accumulate(nums.begin(), nums.end(), 0);
//         int i = 0, j = 0;
//         int currOnes = 0, maxCount = 0;
//         while (j < 2 * n) {
//             if (temp[j] == 1) {
//                 currOnes++;
//             }
//             if (j - i + 1 > totalOnes) {
//                 currOnes -= temp[i];
//                 i++;
//             }
//             maxCount = max(maxCount, currOnes);
//             j++;
//         }
//         return totalOnes - maxCount;
//     }
// };






// TLE
// class Solution {
// public:
//     int minSwaps(vector<int>& nums) {
//         int one = 0;
//         int n = nums.size();
//         for (int i = 0; i < n; i++) {
//             if (nums[i] == 1) {
//                 one++;
//             }
//         }
//         int ans = INT_MAX;
//         nums.insert(nums.end(), nums.begin(), nums.end());
//         for (int i = 0; i < 2 *n - one; i++) {
//             int zero = 0;
//             for (int j = i; j < i + one; j++) {
//                 if (nums[j] == 0) {
//                     zero++;
//                 }
//             }
//             ans = min(ans, zero);
//         }
//         return ans;
//     }
// };