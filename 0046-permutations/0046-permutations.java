class Solution {

    public void backTrack(int[] nums, int i, List<List<Integer>> result) {
        if (i == nums.length - 1) {
            List<Integer> permutation = new ArrayList<>();
            for (int num : nums) {
                permutation.add(num);
            }
            result.add(permutation);
            return;
        }
        for (int j = i; j < nums.length; j++) {
            swap(nums, i, j);
            backTrack(nums, i + 1, result);
            swap(nums, i, j);
        }
    }

    public void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        backTrack(nums, 0, result);
        return result;
    }
}