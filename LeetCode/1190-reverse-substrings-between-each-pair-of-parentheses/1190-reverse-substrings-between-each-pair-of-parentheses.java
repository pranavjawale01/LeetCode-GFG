class Solution {
    public String reverseParentheses(String s) {
        int n = s.length();
        Stack<Integer> openBracket = new Stack<>();
        int[] door = new int[n];

        for (int i = 0; i < n; ++i) {
            if (s.charAt(i) == '(') {
                openBracket.push(i);
            } else if (s.charAt(i) == ')') {
                int j = openBracket.pop();
                door[i] = j;
                door[j] = i;
            }
        }

        StringBuilder result = new StringBuilder();
        int direction = 1;
        for (int i = 0; i < n; i += direction) {
            if (s.charAt(i) == '(' || s.charAt(i) == ')') {
                i = door[i];
                direction = -direction;
            } else {
                result.append(s.charAt(i));
            }
        }
        return result.toString();
    }
}





// class Solution {
//     public void reverse(StringBuilder s, int i, int j) {
//         while (i < j) {
//             char temp = s.charAt(i);
//             s.setCharAt(i, s.charAt(j));
//             s.setCharAt(j, temp);
//             i++;
//             j--;
//         }
//     }
//     public String reverseParentheses(String s) {
//         Stack<Integer> st = new Stack<>();
//         StringBuilder str = new StringBuilder();
//         for (char c : s.toCharArray()) {
//             if (c == '(') {
//                 st.push(str.length());
//             } else if (c == ')') {
//                 int start = st.pop();
//                 reverse(str, start, str.length() - 1);
//             } else {
//                 str.append(c);
//             }
//         }
//         return str.toString();
//     }
// }