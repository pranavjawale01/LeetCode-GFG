class Solution {
    public int[] getSneakyNumbers(int[] nums) {
        Map<Integer, Integer> mp = new HashMap<>();
        for (int x : nums) {
            mp.put(x, mp.getOrDefault(x, 0) + 1);
        }
        List<Integer> sneakyNumbers = new ArrayList<>();
        for (Map.Entry<Integer, Integer> x : mp.entrySet()) {
            if (x.getValue() > 1) {
                sneakyNumbers.add(x.getKey());
            }
        }        
        int[] ans = new int[sneakyNumbers.size()];
        for (int i = 0; i < sneakyNumbers.size(); i++) {
            ans[i] = sneakyNumbers.get(i);
        }        
        return ans;
    }
}