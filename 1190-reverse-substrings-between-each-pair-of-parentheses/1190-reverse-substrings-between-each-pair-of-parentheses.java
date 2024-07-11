class Solution {
    public void reverse(StringBuilder s, int i, int j) {
        while (i < j) {
            char temp = s.charAt(i);
            s.setCharAt(i, s.charAt(j));
            s.setCharAt(j, temp);
            i++;
            j--;
        }
    }
    public String reverseParentheses(String s) {
        Stack<Integer> st = new Stack<>();
        StringBuilder str = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (c == '(') {
                st.push(str.length());
            } else if (c == ')') {
                int start = st.pop();
                reverse(str, start, str.length() - 1);
            } else {
                str.append(c);
            }
        }
        return str.toString();
    }
}