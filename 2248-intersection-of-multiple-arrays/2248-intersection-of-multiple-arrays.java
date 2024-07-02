class Solution {
    public List<Integer> intersection(int[][] nums) {
        int n = nums.length;
        Map<Integer, Integer> mp = new HashMap<>();
        for (int[] num : nums) {
            for (int x : num) {
                mp.put(x, mp.getOrDefault(x, 0) + 1);
            }
        }
        List<Integer> ans = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry : mp.entrySet()) {
            if (entry.getValue() == n) {
                ans.add(entry.getKey());
            }
        }
        Collections.sort(ans);
        return ans;
    }
}