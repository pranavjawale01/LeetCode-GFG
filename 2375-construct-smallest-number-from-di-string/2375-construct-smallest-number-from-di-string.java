class Solution {
    public String smallestNumber(String pattern) {
        int n = pattern.length();
        StringBuilder ans = new StringBuilder();
        int counter = 1;
        Stack<Character> st = new Stack<>();

        for (int i = 0; i <= n; i++) {
            st.push((char) (counter + '0'));
            counter++;
            if (i == n || pattern.charAt(i) == 'I') {
                while (!st.isEmpty()) {
                    ans.append(st.pop());
                }
            }
        }
        return ans.toString();
    }
}