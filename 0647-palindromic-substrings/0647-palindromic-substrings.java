class Solution {
    int count = 0;
    
    void check(String s, int i, int j, int n) {
        while (i >= 0 && j < n && s.charAt(i) == s.charAt(j)) {
            count++;
            i--;
            j++;
        }
    }
    
    public int countSubstrings(String s) {
        int n = s.length();
        count = 0;
        for (int i = 0; i < n; i++) {
            check(s, i, i, n);
            check(s, i, i + 1, n);
        }
        return count;
    }
}


// class Solution {
//     public int countSubstrings(String s) {
//         int n = s.length();
//         boolean[][] t = new boolean[n][n];
//         int count = 0;
        
//         for (int L = 1; L <= n; L++) {
//             for (int i = 0; i + L <= n; i++) {
//                 int j = i + L - 1;
//                 if (i == j) {
//                     t[i][j] = true;
//                 } else if (i + 1 == j) {
//                     t[i][j] = (s.charAt(i) == s.charAt(j));
//                 } else {
//                     t[i][j] = (s.charAt(i) == s.charAt(j) && t[i + 1][j - 1]);
//                 }
//                 if (t[i][j]) {
//                     count++;
//                 }
//             }
//         }
        
//         return count;
//     }
// }

// // class Solution {
// //     int[][] t = new int[1001][1001];
    
// //     boolean isPalindrome(String s, int start, int end) {
// //         if (start > end) {
// //             return true;
// //         }
// //         if (t[start][end] != -1) {
// //             return t[start][end] == 1;
// //         }
// //         if (s.charAt(start) == s.charAt(end)) {
// //             return isPalindrome(s, start + 1, end - 1);
// //         }
// //         return false;
// //     }
    
// //     public int countSubstrings(String s) {
// //         int n = s.length();
// //         for (int[] row : t) {
// //             Arrays.fill(row, -1);
// //         }
// //         int count = 0;
// //         for (int i = 0; i < n; i++) {
// //             for (int j = i; j < n; j++) {
// //                 if (isPalindrome(s, i, j)) {
// //                     count++;
// //                 }
// //             }
// //         }
// //         return count;
// //     }
// // }


// // // class Solution {
// // //     public boolean isPalindrome(String s, int start, int end) {
// // //         while (start < end) {
// // //             if (s.charAt(start) != s.charAt(end)) {
// // //                 return false;
// // //             }
// // //             start++;
// // //             end--;
// // //         }
// // //         return true;
// // //     }
    
// // //     public int countSubstrings(String s) {
// // //         int n = s.length();
// // //         int count = 0;
// // //         for (int i = 0; i < n; i++) {
// // //             for (int j = i; j < n; j++) {
// // //                 String t = s.substring(i, j + 1);
// // //                 if (isPalindrome(s, i, j)) {
// // //                     count++;
// // //                 }
// // //             }
// // //         }
// // //         return count;
// // //     }
// // // }