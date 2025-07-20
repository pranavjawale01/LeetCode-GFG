class Solution {
    public int minAddToMakeValid(String s) {
        int open = 0, close = 0;
        for (char c : s.toCharArray()) {
            if (c == '(') {
                open++;
            } else {
                if (open == 0) {
                    close++;
                } else {
                    open--;
                }
            }
        }
        return open + close;
    }
}












// class Solution {
//     public int minAddToMakeValid(String s) {
//         Stack<Character> st = new Stack<>();
//         int count = 0;
//         for (char c : s.toCharArray()) {
//             if (c == '(') {
//                 st.push(c);
//             } else {
//                 if (st.isEmpty()) {
//                     count++;
//                 } else {
//                     st.pop();
//                 }
//             }
//         }
//         return st.size() + count;
//     }
// }