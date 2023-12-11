class Solution {
    public int findSpecialInteger(int[] arr) {
        Map<Integer, Integer> counter = new HashMap<Integer, Integer>();
        for (int num : arr) {
            counter.put(num, counter.getOrDefault(num, 0) + 1);
        }
        for (Map.Entry<Integer, Integer> entry : counter.entrySet()) {
            if (entry.getValue() > arr.length / 4) {
                return entry.getKey();
            }
        }
        return 0;
    }
}