class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0, j = 0, count = 0;
        int m = haystack.size(), n = needle.size();
        for (int i = 0; i < m; i++) {
            if (haystack[i] != needle[j]) {
                j = 0;
                i = count;
                count++;
            } else {
                j++;
            }
            if (j == n) {
                return count;
            }
        }
        return -1;
    }
};

// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         int n = haystack.size(), m = needle.size();
//         for (int i = 0; i <= n - m; i++) {
//             bool flag = true;
//             for (int j = 0; j < m; j++) {
//                 if (haystack[j+i] != needle[j]) {
//                     flag = false;
//                     break;
//                 }
//             }
//             if (flag) {
//                 return i;
//             }
//         }
//         return -1;
//     }
// };