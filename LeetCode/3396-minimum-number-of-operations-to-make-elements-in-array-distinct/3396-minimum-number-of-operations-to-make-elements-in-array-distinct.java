class Solution {
    public int minimumOperations(int[] nums) {
        int n = nums.length;
        Map<Integer, Integer> mp = new HashMap<>();
        
        for (int num : nums) {
            mp.put(num, mp.getOrDefault(num, 0) + 1);
        }

        if (mp.size() == n) {
            return 0;
        }
        
        int ans = 0;
        List<Integer> numList = new ArrayList<>();
        for (int num : nums) {
            numList.add(num);
        }
        
        while (!numList.isEmpty()) {
            for (int i = 0; i < 3 && !numList.isEmpty(); i++) {
                int first = numList.get(0);
                mp.put(first, mp.get(first) - 1);
                if (mp.get(first) == 0) {
                    mp.remove(first);
                }
                numList.remove(0);
            }
            ans++;
            
            if (mp.size() == numList.size()) {
                break;
            }
        }
        
        return ans;
    }
}