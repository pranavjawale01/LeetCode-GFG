class Solution {
    public long countCompleteDayPairs(int[] hours) {
        Map<Integer, Integer> mp = new HashMap<>();
        long count = 0;
        for (int hour : hours) {
            int mod = hour % 24;
            int com = (24 - mod) % 24;
            if (mp.containsKey(com)) {
                count += mp.get(com);
            }
            mp.put(mod, mp.getOrDefault(mod, 0) + 1);
        }
        return count;
    }
}