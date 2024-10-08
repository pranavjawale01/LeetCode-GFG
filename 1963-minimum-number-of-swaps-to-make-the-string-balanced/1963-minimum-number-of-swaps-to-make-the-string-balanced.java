class Solution {
    public int minSwaps(String s) {
        int size = 0;
        for (char c : s.toCharArray()) {
            if (c == '[') {
                size++;
            } else if (size != 0) {
                size--;
            }
        }
        return (size + 1) / 2;
    }
}








// class Solution {
//     public int minSwaps(String s) {
//         Stack<Character> st = new Stack<>();
//         for (char c : s.toCharArray()) {
//             if (c == '[') {
//                 st.push(c);
//             } else if (!st.isEmpty()) {
//                 st.pop();
//             }
//         }
//         return (st.size() + 1) / 2;
//     }
// }