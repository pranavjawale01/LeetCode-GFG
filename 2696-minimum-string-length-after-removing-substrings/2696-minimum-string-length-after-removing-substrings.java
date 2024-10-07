class Solution {
    public int minLength(String s) {
        Stack<Character> st = new Stack<>();
        
        for (char c : s.toCharArray()) {
            if (st.isEmpty()) {
                st.push(c);
            } else {
                if (c == 'B' && st.peek() == 'A') {
                    st.pop();
                } else if (c == 'D' && st.peek() == 'C') {
                    st.pop();
                } else {
                    st.push(c);
                }
            }
        }
        
        return st.size();
    }
}





// class Solution {
//     public int minLength(String s) {
//         while (s.contains("AB") || s.contains("CD")) {
//             if (s.contains("AB")) {
//                 s = s.replaceFirst("AB", "");
//             } else if (s.contains("CD")) {
//                 s = s.replaceFirst("CD", "");
//             }
//         }
//         return s.length();
//     }
// }