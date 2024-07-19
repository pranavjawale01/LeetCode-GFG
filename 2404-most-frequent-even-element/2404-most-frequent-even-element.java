class Solution {
    public int mostFrequentEven(int[] nums) {
        Map<Integer, Integer> freqMap = new HashMap<>();

        for (int num : nums) {
            if (num % 2 == 0) {
                freqMap.put(num, freqMap.getOrDefault(num, 0) + 1);
            }
        }

        int ans = -1;
        int maxCount = 0;

        for (Map.Entry<Integer, Integer> entry : freqMap.entrySet()) {
            int key = entry.getKey();
            int value = entry.getValue();

            if (value > maxCount || (value == maxCount && key < ans)) {
                maxCount = value;
                ans = key;
            }
        }

        return ans;
    }
}