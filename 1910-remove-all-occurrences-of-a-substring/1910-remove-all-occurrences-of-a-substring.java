class Solution {
    public String removeOccurrences(String s, String part) {
        StringBuilder ans = new StringBuilder();
        int n = part.length();

        for (char c : s.toCharArray()) {
            ans.append(c);
            if (ans.length() >= n && ans.substring(ans.length() - n).equals(part)) {
                ans.setLength(ans.length() - n);
            }
        }
        return ans.toString();
    }
}






// class Solution {
//     public String removeOccurrences(String s, String part) {
//         Stack<Character> st = new Stack<>();
//         int n = part.length();

//         for (char ch : s.toCharArray()) {
//             st.push(ch);
//             if (st.size() >= n) {
//                 boolean match = true;
//                 for (int i = 0; i < n; i++) {
//                     if (st.get(st.size() - n + i) != part.charAt(i)) {
//                         match = false;
//                         break;
//                     }
//                 }
//                 if (match) {
//                     for (int i = 0; i < n; i++) {
//                         st.pop();
//                     }
//                 }
//             }
//         }

//         StringBuilder ans = new StringBuilder();
//         for (char ch : st) {
//             ans.append(ch);
//         }
//         return ans.toString();
//     }
// }






// // class Solution {
// //     public String removeOccurrences(String s, String part) {
// //         while (s.contains(part)) {
// //             s = s.replaceFirst(part, "");
// //         }
// //         return s;
// //     }
// // }