class Solution {
    public int maxOperations(String s) {
        StringBuilder t = new StringBuilder();
        t.append(s.charAt(0));
        int count = 0, one = 0;

        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == '1') {
                t.append('1');
            } else {
                if (s.charAt(i) != s.charAt(i - 1)) {
                    t.append(s.charAt(i));
                }
            }
        }

        for (char c : t.toString().toCharArray()) {
            if (c == '1') {
                one++;
            } else {
                count += one;
            }
        }

        return count;
    }
}