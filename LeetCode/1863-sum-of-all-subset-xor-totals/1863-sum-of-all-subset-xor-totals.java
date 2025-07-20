class Solution {
    public int subsetXORSum(int[] nums) {
        int ans = 0;
        int n = nums.length;
        for (int num : nums) {
            ans |= num;
        }
        return ans << (n - 1);
    }
}


// class Solution {
//     public int solve(int[] nums, int i, int xor) {
//         if (i == nums.length) {
//             return xor;
//         }
//         return solve(nums, i+1, nums[i] ^ xor) + solve(nums, i+1, xor);
//     }

//     public int subsetXORSum(int[] nums) {
//         return solve(nums, 0, 0);
//     }
// }




// class Solution {
//     public void solve(int[] nums, int i, List<Integer> currSubset, List<List<Integer>> subsets) {
//         if (i == nums.length) {
//             subsets.add(new ArrayList<>(currSubset));
//             return;
//         }
//         currSubset.add(nums[i]);
//         solve(nums, i+1, currSubset, subsets);
//         currSubset.remove(currSubset.size() - 1);
//         solve(nums, i+1, currSubset, subsets);
//     }

//     public int subsetXORSum(int[] nums) {
//         List<List<Integer>> subsets = new ArrayList<>();
//         List<Integer> currSubset = new ArrayList<>();
//         solve(nums, 0, currSubset, subsets);
//         int result = 0;
//         for (List<Integer> subset : subsets) {
//             int xorSum = 0;
//             for (int num : subset) {
//                 xorSum ^= num;
//             }
//             result += xorSum;
//         }
//         return result;
//     }
// }