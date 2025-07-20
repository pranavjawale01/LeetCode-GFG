class Solution {
public:
    int solve(int n1, int n2) {
        for (int i = n1; i > 1; i--) {
            if (n2 % i == 0) return i;
        }
        return -1;
    }
    int minOperations(vector<int>& nums) {
        int ans = 0;
        for (int i = nums.size() - 1; i > 0; i--) {
            if (nums[i] < nums[i-1]) {
                nums[i-1] = solve(nums[i], nums[i-1]);
                if (nums[i-1] == -1) return -1;
                ans++;
            }
        }
        return ans;
    }
};








// TLE
// class Solution {
// public:
//     vector<int> solve(int maxVal) {
//         vector<int> arr(maxVal + 1, 1);
//         for (int i = 2; i <= maxVal; i++) {
//             for (int j = 2 * i; j <= maxVal; j += i) {
//                 arr[j] = i;
//             }
//         }
//         return arr;
//     }
//     int minOperations(vector<int>& nums) {
//         int n = nums.size();
//         int count = 0;
//         int maxVal = *max_element(nums.begin(), nums.end());
//         vector<int> arr = solve(maxVal);
//         for (int i = n - 2; i >= 0; i--) {
//             while (nums[i] > nums[i+1]) {
//                 int x = arr[nums[i]];
//                 if (x == 1) return -1;
//                 nums[i] /= x;
//                 count++;
//                 if (nums[i] <= nums[i+1]) break;
//             }
//         }
//         return count;
//     }
// };





// TLE
// class Solution {
// public:
//     int pranavjawale01(int x) {
//         for (int i = x / 2; i >= 1; i--) {
//             if (x % i == 0) return i;
//         }
//         return 1;
//     }
//     int minOperations(vector<int>& nums) {
//         int n = nums.size();
//         int count = 0;
//         for (int i = n - 2; i >= 0; i--) {
//             while (nums[i] > nums[i+1]) {
//                 int x = pranavjawale01(nums[i]);
//                 if (x == 1) return -1;
//                 nums[i] /= x;
//                 count++;
//                 if (nums[i] <= nums[i+1]) break;
//             }
//             if (nums[i] > nums[i+1]) return -1;
//         }
//         return count;
//     }
// };