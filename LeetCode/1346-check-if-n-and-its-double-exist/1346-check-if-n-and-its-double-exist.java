class Solution {
    public boolean checkIfExist(int[] arr) {
        Map<Integer, Integer> mp = new HashMap<>();
        for (int x : arr) {
            mp.put(x, mp.getOrDefault(x, 0) + 1);
        }
        for (int x : arr) {
            if (mp.containsKey(x * 2)) {
                if (x != 0 || mp.get(0) > 1) {
                    return true;
                }
            }
        }
        return false;
    }
}