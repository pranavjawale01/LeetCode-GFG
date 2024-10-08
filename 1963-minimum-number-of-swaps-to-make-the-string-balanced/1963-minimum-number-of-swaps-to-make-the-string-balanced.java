class Solution {
    public int minSwaps(String s) {
        Stack<Character> st = new Stack<>();
        for (char c : s.toCharArray()) {
            if (c == '[') {
                st.push(c);
            } else if (!st.isEmpty()) {
                st.pop();
            }
        }
        return (st.size() + 1) / 2;
    }
}