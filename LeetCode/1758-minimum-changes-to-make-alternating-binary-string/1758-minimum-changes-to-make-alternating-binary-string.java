public class Solution {
    public int minOperations(String s) {
        int n = s.length();
        int count0 = 0;
        int count1 = 0;

        for (int i = 0; i < n; ++i) {
            if (s.charAt(i) != '0' + i % 2) {
                count0++;
            } else {
                count1++;
            }
        }

        return Math.min(count0, count1);
    }
}