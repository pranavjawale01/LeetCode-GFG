class Solution {
    private int ans;
    private int K;
    public void dfs(int[] nums, int i, Map<Integer, Integer> mp) {
        if (i == nums.length) {
            ans++;
            return;
        }
        dfs(nums, i+1, mp);
        if (!mp.containsKey(nums[i] - K) && !mp.containsKey(nums[i]+K)) {
            mp.put(nums[i], mp.getOrDefault(nums[i], 0) + 1);
            dfs(nums, i+1, mp);
            mp.put(nums[i], mp.get(nums[i]) - 1);
            if (mp.get(nums[i]) == 0) {
                mp.remove(nums[i]);
            }
        }
    }
    public int beautifulSubsets(int[] nums, int k) {
        ans = 0;
        K = k;
        Map<Integer, Integer> mp = new HashMap<>();
        dfs(nums, 0, mp);
        return ans - 1;
    }
}