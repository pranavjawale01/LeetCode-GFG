class Solution {
    public char findKthBit(int n, int k) {
        if (n == 1) {
            return '0';
        }

        int len = (1 << n) - 1;
        
        if (k < (len + 1) / 2) {
            return findKthBit(n - 1, k);
        } else if (k == (len + 1) / 2) {
            return '1';
        } else {
            char ch = findKthBit(n - 1, len - k + 1);
            return (ch == '0') ? '1' : '0';
        }
    }
}





// class Solution {
//     public char findKthBit(int n, int k) {
//         String s = "0";
        
//         for (int i = 2; i <= n; i++) {
//             StringBuilder inverted = new StringBuilder(s);
//             for (int j = 0; j < inverted.length(); j++) {
//                 inverted.setCharAt(j, inverted.charAt(j) == '0' ? '1' : '0');
//             }
//             inverted.reverse();
//             s = s + "1" + inverted.toString();
//         }
        
//         return s.charAt(k - 1);
//     }
// }