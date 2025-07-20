class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n - 1, k = n - 1;
        vector<int> ans(n, 0);
        while (k >= 0) {
            int a = nums[i] * nums[i];
            int b = nums[j] * nums[j];
            if (a > b) {
                ans[k] = a;
                i++;
            } else {
                ans[k] = b;
                j--;
            }
            k--;
        }
        return ans;
    }
};


// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         int n = nums.size();
//         for (int i = 0; i < n; i++) {
//             nums[i] = nums[i] * nums[i];
//         }
//         sort(nums.begin(), nums.end());
//         return nums;
//     }
// };