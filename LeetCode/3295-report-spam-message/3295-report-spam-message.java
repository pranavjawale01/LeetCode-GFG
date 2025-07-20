class Solution {
    public boolean reportSpam(String[] message, String[] bannedWords) {
        Set<String> st = new HashSet<>();
        for (String s : bannedWords) {
            st.add(s);
        }
        int count = 0;
        for (String s : message) {
            if (st.contains(s)) {
                count++;
            }
        }
        return count >= 2;
    }
}