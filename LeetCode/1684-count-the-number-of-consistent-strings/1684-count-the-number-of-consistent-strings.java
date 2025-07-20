class Solution {
    public int countConsistentStrings(String allowed, String[] words) {
        int mask = 0;
        for (char c : allowed.toCharArray()) {
            mask |= 1 << (c - 'a');
        }
        int count = 0;
        for (String s : words) {
            boolean flag = true;
            for (char c : s.toCharArray()) {
                if (((mask >> (c - 'a')) & 1) == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                count++;
            }
        }
        return count;
    }
}






// class Solution {
//     public int countConsistentStrings(String allowed, String[] words) {
//         Set<Character> st = new HashSet<>();
//         for (char c : allowed.toCharArray()) {
//             st.add(c);
//         }
//         int count = 0;
//         for (String s : words) {
//             boolean flag = false;
//             for (char c : s.toCharArray()) {
//                 if (!st.contains(c)) {
//                     flag = true;
//                     break;
//                 }
//             }
//             if (flag) {
//                 continue;
//             }
//             count++;
//         }
//         return count;
//     }
// }