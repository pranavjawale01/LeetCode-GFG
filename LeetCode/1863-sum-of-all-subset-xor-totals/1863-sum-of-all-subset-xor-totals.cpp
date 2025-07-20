class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for (int &num : nums) {
            ans |= num;
        }
        return ans << (n - 1);
    }
};



// class Solution {
// public:
//     int solve(vector<int> &nums, int i, int xor_val) {
//         if (i == nums.size()) {
//             return xor_val;
//         }
//         return solve(nums, i+1, nums[i] ^ xor_val) + solve(nums, i+1, xor_val);
//     }

//     int subsetXORSum(vector<int>& nums) {
//         return solve(nums, 0, 0);
//     }
// };




// class Solution {
// public:
//     void solve(vector<int> &nums, int i, vector<int> &currSubset, vector<vector<int>> &subsets) {
//         if (i == nums.size()) {
//             subsets.push_back(currSubset);
//             return;
//         }
//         currSubset.push_back(nums[i]);
//         solve(nums, i+1, currSubset, subsets);
//         currSubset.pop_back();
//         solve(nums, i+1, currSubset, subsets);
//     }

//     int subsetXORSum(vector<int>& nums) {
//         vector<vector<int>> subsets;
//         vector<int> currSubset;
//         solve(nums, 0, currSubset, subsets);
//         int result = 0;
//         for (vector<int> &subset : subsets) {
//             int xorSum = 0;
//             for (int &num : subset) {
//                 xorSum ^= num;
//             }
//             result += xorSum;
//         }
//         return result;
//     }
// };