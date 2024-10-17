class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    
    void solve(int idx, int[] nums, List<Integer> res) {
        ans.add(new ArrayList<>(res));
        
        for (int i = idx; i < nums.length; i++) {
            if (i > idx && nums[i] == nums[i - 1]) {
                continue;
            }
            res.add(nums[i]);
            solve(i + 1, nums, res);
            res.remove(res.size() - 1);
        }
    }

    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<Integer> res = new ArrayList<>();
        Arrays.sort(nums);
        solve(0, nums, res);
        return ans;
    }
}