class Solution {
    public int countConsistentStrings(String allowed, String[] words) {
        Set<Character> st = new HashSet<>();
        for (char c : allowed.toCharArray()) {
            st.add(c);
        }
        int count = 0;
        for (String s : words) {
            boolean flag = false;
            for (char c : s.toCharArray()) {
                if (!st.contains(c)) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                continue;
            }
            count++;
        }
        return count;
    }
}