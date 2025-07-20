class Solution {
    public String minRemoveToMakeValid(String s) {
        StringBuilder result = new StringBuilder();
        int n = s.length();
        
        int lastOpen = 0;
        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            if ((c >= 'a' && c <= 'z'))
                result.append(c);
            else if (c == '(') {
                result.append(c);
                lastOpen++;
            } else if (lastOpen > 0) {
                lastOpen--;
                result.append(c);
            }
        }
        
        if (result.length() == 0)
            return "";
        
        s = result.toString();
        result = new StringBuilder();
        int lastClose = 0;
        n = s.length();

        for (int i = n - 1; i >= 0; i--) {
            char c = s.charAt(i);
            if ((c >= 'a' && c <= 'z'))
                result.insert(0, c);
            else if (c == ')') {
                result.insert(0, c);
                lastClose++;
            } else if (lastClose > 0) {
                lastClose--;
                result.insert(0, c);
            }
        }
        return result.toString();
    }
}

// class Solution {
//     public String minRemoveToMakeValid(String s) {
//         int open = 0;
//         StringBuilder temp = new StringBuilder();

//         for (char c : s.toCharArray()) {
//             if (c == '(') {
//                 open++;
//             } else if (c == ')') {
//                 if (open == 0)
//                     continue;
//                 open--;
//             }

//             temp.append(c);
//         }

//         int n = temp.length();
//         StringBuilder result = new StringBuilder();
//         for (int i = n - 1; i >= 0; i--) {
//             if (temp.charAt(i) == '(' && open-- > 0)
//                 continue;
//             result.append(temp.charAt(i));
//         }

//         return result.reverse().toString();
//     }
// }

// // class Solution {
// //     public String minRemoveToMakeValid(String s) {
// //         Set<Integer> idx = new HashSet<>();
// //         Stack<Integer> st = new Stack<>();
// //         int n = s.length();
// //         for (int i = 0; i < n; i++) {
// //             if (s.charAt(i) == '(') {
// //                 st.push(i);
// //             } else if (s.charAt(i) == ')') {
// //                 if (st.isEmpty()) {
// //                     idx.add(i);
// //                 } else {
// //                     st.pop();
// //                 }
// //             }
// //         }
// //         while (!st.isEmpty()) {
// //             idx.add(st.pop());
// //         }
// //         StringBuilder ans = new StringBuilder();
// //         for (int i = 0; i < n; i++) {
// //             if (!idx.contains(i)) {
// //                 ans.append(s.charAt(i));
// //             }
// //         }
// //         return ans.toString();
// //     }
// // }