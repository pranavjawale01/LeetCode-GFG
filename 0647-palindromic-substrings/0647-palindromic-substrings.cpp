class Solution {
public:
    int count = 0;
    void check(string& s, int i, int j, int n) {
        
        while(i >= 0 && j < n && s[i] == s[j]) {
            count++;
            i--;
            j++;
        }
    }
    int countSubstrings(string s) {
        int n = s.length();
        count = 0;
        for(int i = 0; i<n; i++) {
            check(s, i, i, n);
            check(s, i, i+1, n);
        }
        return count;
    }
};
// class Solution {
// public:
//     int countSubstrings(string s) {
//         int n = s.length();
//         vector<vector<bool>> t(n, vector<bool>(n, false));
//         int count = 0;
        
//         for (int L = 1; L <= n; L++) {
//             for (int i = 0; i + L <= n; i++) {
//                 int j = i + L - 1;
//                 if (i == j) {
//                     t[i][j] = true;
//                 } else if(i+1 == j) {
//                     t[i][j] = (s[i] == s[j]);
//                 } else {
//                     t[i][j] = (s[i] == s[j] && t[i+1][j-1]); 
//                 }
//                 if (t[i][j] == true) {
//                     count++;
//                 }
//             }
//         }
        
//         return count;
//     }
// };

// // class Solution {
// // public:
// //     int t[1001][1001];
// //     bool isPalindrome(string &s, int start, int end) {
// //         if (start > end) {
// //             return true;
// //         }
// //         if (t[start][end] != -1) {
// //             return t[start][end];
// //         }
// //         if (s[start] == s[end]) {
// //             return t[start][end] = isPalindrome(s, start+1, end-1);
// //         }
// //         return t[start][end] = false;
// //     }
    
// //     int countSubstrings(string s) {
// //         int n = s.length();
// //         memset(t, -1, sizeof(t));
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
// // };

// // // class Solution {
// // // public:
// // //     bool isPalindrome(string &s, int start, int end) {
// // //         while (start < end) {
// // //             if (s[start] != s[end]) {
// // //                 return false;
// // //             }
// // //             start++;
// // //             end--;
// // //         }
// // //         return true;
// // //     }
    
// // //     int countSubstrings(string s) {
// // //         int n = s.length();
// // //         int count = 0;
// // //         for (int i = 0; i < n; i++) {
// // //             for (int j = i; j < n; j++) {
// // //                 string t = s.substr(i, j - i + 1);
// // //                 if (isPalindrome(t, 0, t.length() - 1)) {
// // //                     count++;
// // //                 }
// // //             }
// // //         }
// // //         return count;
// // //     }
// // // };