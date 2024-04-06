class Solution {
    public String minRemoveToMakeValid(String s) {
        Set<Integer> idx = new HashSet<>();
        Stack<Integer> st = new Stack<>();
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '(') {
                st.push(i);
            } else if (s.charAt(i) == ')') {
                if (st.isEmpty()) {
                    idx.add(i);
                } else {
                    st.pop();
                }
            }
        }
        while (!st.isEmpty()) {
            idx.add(st.pop());
        }
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < n; i++) {
            if (!idx.contains(i)) {
                ans.append(s.charAt(i));
            }
        }
        return ans.toString();
    }
}