class Solution {
    public int minAddToMakeValid(String s) {
        Stack<Character> st = new Stack<>();
        int count = 0;
        for (char c : s.toCharArray()) {
            if (c == '(') {
                st.push(c);
            } else {
                if (st.isEmpty()) {
                    count++;
                } else {
                    st.pop();
                }
            }
        }
        return st.size() + count;
    }
}