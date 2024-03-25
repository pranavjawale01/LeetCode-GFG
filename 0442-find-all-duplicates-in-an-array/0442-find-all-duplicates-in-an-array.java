class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        Map<Integer, Integer> mp = new HashMap<>();
        List<Integer> ans = new ArrayList<>();
        for (int num : nums) {
            mp.put(num, mp.getOrDefault(num, 0) + 1);
            if (mp.get(num) > 1) {
                ans.add(num);
            }
        }
        return ans;
    }
}