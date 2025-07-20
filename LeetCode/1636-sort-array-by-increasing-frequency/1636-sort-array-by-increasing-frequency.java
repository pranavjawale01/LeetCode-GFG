class Solution {
    public int[] frequencySort(int[] nums) {
        Map<Integer, Integer> freqMap = new HashMap<>();
        for (int num : nums) {
            freqMap.put(num, freqMap.getOrDefault(num, 0) + 1);
        }

        Integer[] numsBoxed = Arrays.stream(nums).boxed().toArray(Integer[]::new);

        Arrays.sort(numsBoxed, (a, b) -> {
            int freqA = freqMap.get(a);
            int freqB = freqMap.get(b);
            if (freqA == freqB) {
                return b - a;
            }
            return freqA - freqB;
        });

        return Arrays.stream(numsBoxed).mapToInt(Integer::intValue).toArray();
    }
}