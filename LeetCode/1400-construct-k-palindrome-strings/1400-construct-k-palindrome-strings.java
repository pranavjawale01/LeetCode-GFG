class Solution {
    public boolean canConstruct(String s, int k) {
        if (k > s.length()) return false;
        
        HashMap<Character, Integer> freq = new HashMap<>();
        for (char c : s.toCharArray()) {
            freq.put(c, freq.getOrDefault(c, 0) + 1);
        }

        int oddCount = 0;
        for (int count : freq.values()) {
            if (count % 2 != 0) {
                oddCount++;
            }
        }

        return oddCount <= k;
    }
}