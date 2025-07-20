class Solution {
    public int numSteps(String s) {
        int n = s.length();
        int op = 0;
        int carry = 0;
        for (int i = n - 1; i >= 1; i--) {
            if (((s.charAt(i) - '0') + carry) % 2 == 1) {
                op += 2;
                carry = 1;
            } else {
                op += 1;
            }
        }
        return op + carry;
    }
}




// class Solution {
//     public int numSteps(String s) {
//         int count = 0;
//         StringBuilder sb = new StringBuilder(s);
//         while (!sb.toString().equals("1")) {
//             if (sb.charAt(sb.length()-1) == '0') {
//                 sb.deleteCharAt(sb.length() - 1);
//             } else {
//                 int i = sb.length() - 1;
//                 while (i >= 0 && sb.charAt(i) == '1') {
//                     sb.setCharAt(i, '0');
//                     i--;
//                 }
//                 if (i >= 0) {
//                     sb.setCharAt(i, '1');
//                 } else {
//                     sb.insert(0, '1');
//                 }
//             }
//             count++;
//         }
//         return count;
//     }
// }