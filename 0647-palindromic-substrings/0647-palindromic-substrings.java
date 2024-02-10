class Solution {
    int[][] t = new int[1001][1001];
    
    boolean isPalindrome(String s, int start, int end) {
        if (start > end) {
            return true;
        }
        if (t[start][end] != -1) {
            return t[start][end] == 1;
        }
        if (s.charAt(start) == s.charAt(end)) {
            return isPalindrome(s, start + 1, end - 1);
        }
        return false;
    }
    
    public int countSubstrings(String s) {
        int n = s.length();
        for (int[] row : t) {
            Arrays.fill(row, -1);
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(s, i, j)) {
                    count++;
                }
            }
        }
        return count;
    }
}


// class Solution {
//     public boolean isPalindrome(String s, int start, int end) {
//         while (start < end) {
//             if (s.charAt(start) != s.charAt(end)) {
//                 return false;
//             }
//             start++;
//             end--;
//         }
//         return true;
//     }
    
//     public int countSubstrings(String s) {
//         int n = s.length();
//         int count = 0;
//         for (int i = 0; i < n; i++) {
//             for (int j = i; j < n; j++) {
//                 String t = s.substring(i, j + 1);
//                 if (isPalindrome(s, i, j)) {
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// }