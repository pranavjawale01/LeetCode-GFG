class Solution {
    private String padZeroes(String s, int maxLength) {
        StringBuilder sb = new StringBuilder(s);
        while (sb.length() < maxLength) {
            sb.insert(0, '0');
        }
        return sb.toString();
    }

    public boolean check(int x, int y) {
        String s1 = String.valueOf(x);
        String s2 = String.valueOf(y);
        int n = s1.length();
        int m = s2.length();
        int maxlen = Math.max(n, m);

        s1 = padZeroes(s1, maxlen);
        s2 = padZeroes(s2, maxlen);

        int diff = 0;
        Map<Character, Integer> mp1 = new HashMap<>();
        Map<Character, Integer> mp2 = new HashMap<>();

        for (int i = 0; i < maxlen; i++) {
            if (s1.charAt(i) != s2.charAt(i)) {
                diff++;
            }
            mp1.put(s1.charAt(i), mp1.getOrDefault(s1.charAt(i), 0) + 1);
            mp2.put(s2.charAt(i), mp2.getOrDefault(s2.charAt(i), 0) + 1);
        }

        return diff <= 2 && mp1.equals(mp2);
    }

    public int countPairs(int[] nums) {
        int count = 0;
        int n = nums.length;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j] || check(nums[i], nums[j])) {
                    count++;
                }
            }
        }

        return count;
    }
}