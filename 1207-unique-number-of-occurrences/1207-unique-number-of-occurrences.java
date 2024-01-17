class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        Map<Integer, Integer> map = new HashMap<>();
        Set<Integer> set = new HashSet<>();
        for (int x : arr) {
            map.put(x, map.getOrDefault(x,0)+1);
        }
        for (int x : map.values()) {
            if (!set.add(x)) {
                return false;
            }
        }
        return true;
    }
}