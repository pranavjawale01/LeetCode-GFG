class Solution {
    public String maximumOddBinaryNumber(String s) {
        int n = s.length();
        StringBuilder result = new StringBuilder(String.join("", Collections.nCopies(n, "0")));
        int count_1 = 0;
        for (char ch : s.toCharArray()) {
            if (ch == '1') {
                count_1++;
            }
        }
        int j = 0;
        while (count_1 > 1) {
            result.setCharAt(j, '1');
            j++;
            count_1--;
        }
        result.setCharAt(n - 1, '1');
        return result.toString();
    }
}

// class Solution {
//     public String maximumOddBinaryNumber(String s) {
//         int n = s.length();
//         StringBuilder result = new StringBuilder();
//         for (int i = 0; i < n; i++) {
//             result.append('0');
//         }
//         int i = 0;
//         for (char ch : s.toCharArray()) {
//             if (ch == '1') {
//                 if (result.charAt(n-1) == '1') {
//                     result.setCharAt(i, '1');
//                     i++;
//                 } else {
//                     result.setCharAt(n - 1, '1');
//                 }
//             }
//         }
//         return result.toString();
//     }
// }