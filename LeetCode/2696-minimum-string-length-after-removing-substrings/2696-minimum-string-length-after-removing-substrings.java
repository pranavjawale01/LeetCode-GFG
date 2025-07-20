class Solution {
    public int minLength(String s) {
        int n = s.length();
        char[] arr = s.toCharArray();
        int i = 0, j = 1;
        
        while (j < n) {
            if (i < 0) {
                i++;
                arr[i] = arr[j];
            } else if ((arr[i] == 'A' && arr[j] == 'B') || (arr[i] == 'C' && arr[j] == 'D')) {
                i--;
            } else {
                i++;
                arr[i] = arr[j];
            }
            j++;
        }
        
        return i + 1;
    }
}






// class Solution {
//     public int minLength(String s) {
//         Stack<Character> st = new Stack<>();
        
//         for (char c : s.toCharArray()) {
//             if (st.isEmpty()) {
//                 st.push(c);
//             } else {
//                 if (c == 'B' && st.peek() == 'A') {
//                     st.pop();
//                 } else if (c == 'D' && st.peek() == 'C') {
//                     st.pop();
//                 } else {
//                     st.push(c);
//                 }
//             }
//         }
        
//         return st.size();
//     }
// }





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